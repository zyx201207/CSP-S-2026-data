#include<bits/stdc++.h>
using namespace std;
int n,d,cnt,res;
int a[3005];
void dfs(int x,int r,int c,int last){
	if(x==r+1){
		if(c==cnt) res++;
		return ;
	}
	if(x!=r && a[x+1]-a[last]<=d) dfs(x+1,r,c,last);
	dfs(x+1,r,c+1,x);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--){
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int l=1;l<=n;l++){
			for(int r=l+1;r<=n;r++){
				int last=l;
				cnt=0;
				bool f=1;
				for(int i=l+1;i<=r;i++){
					if(a[i]-a[i-1]>d){
						f=0;
						break;
					}
					if(i==r || a[i]-a[last]<=d && a[i+1]-a[last]>d){
						cnt++;
						last=i;
					}
				}
				if(!f) break;
				res=0;
				dfs(l+1,r,0,l);
				if(res==2) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}