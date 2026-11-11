#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,vis[1000005],b[1000005],x[1000005],mn=1e18,s;
int check(){
	long long cnt=0;
	for(int i=1;i<=n;i++){
		if(vis[i])b[++cnt]=x[i];
	}
	for(int i=1;i<cnt;i++){
		if(b[i+1]-b[i]>d)return 0;
	}
	return 1;
}
void dfs(int x,int cnt,int l,int r){
	if(cnt>mn)return;
	if(x>r){
		if(!vis[l]||!vis[r])return;
		if(check()){
			if(cnt==mn)s++;
			else if(cnt<mn){
				mn=cnt;
				s=1;
			}
		}
		return;
	}
	vis[x]=1;
	dfs(x+1,cnt+1,l,r);
	vis[x]=0;
	dfs(x+1,cnt,l,r);
	vis[x]=0;
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)scanf("%lld",&x[i]);
		if(n<=9){
			long long ans=0;
			for(int l=1;l<=n;l++){
				for(int r=l+1;r<=n;r++){
					mn=1e9;
					s=0;
					dfs(l,0,l,r);
					if(s==2){
						ans++;
					}
				}
			}
			printf("%lld\n",ans);
		}else{
			long long dd=x[2]-x[1],xx=d/dd;
			if(xx<=1)cout<<0<<endl;
			else{
				cout<<max(n-xx*2+1,0ll)<<endl;
			}
		}
	}
	return 0;
} 
