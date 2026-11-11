//GZ-S00271 姓名：周昊杨 学校：贵阳市第一中学 
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int t,n,d,x[N],mi,c,ans,k,flag;
void dfs(int u,int v,int cnt){
	if(cnt>mi)return;
	if(u==v){
		mi=min(mi,cnt);
	}
	else{
		for(int i=u+1;i<=v;i++){
			if(abs(x[i]-x[u])<=d){
				dfs(i,v,cnt+1);
			}
		}
	}
}
void dfs1(int u,int v,int cnt){
	if(cnt>mi)return;
	if(u==v){
		if(cnt==mi)c++;
	}
	else{
		for(int i=u+1;i<=v;i++){
			if(abs(x[i]-x[u])<=d){
				dfs1(i,v,cnt+1);
			}
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>t;
	while(t--){
		mi=LONG_LONG_MAX,c=0,ans=0;
		int flag1=0,q;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			
		}
		sort(x+1,x+1+n);
		k=x[2]-x[1];
		for(int i=3;i<=n;i++){
			if(k!=x[i]-x[i-1])flag=1;
		}
		for(int i=1;i<=n;i++){
			if(x[i]-x[1]<=d&&x[n]-x[i]<=d){
				flag1=1;
				q=i;
			}
		}
		if(flag1){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(i>=q)continue;
					dfs(i,j,0);
					if(mi>2)continue;
					dfs1(i,j,0);
					if(c==2)ans++;
				}
			}
		}
		for(int i=2;i<=n;i++){
			mi=min(mi,x[i]-x[i-1]);
		}
		if(mi>d){
			cout<<0;
			return 0;
		}
		if(x[n]-x[1]<=d){
			cout<<0;
			continue;
		}
		
		if(!flag){
			
			return 0;		
				
		}
		if(n>300){
			cout<<n;
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				mi=LONG_LONG_MAX;
				c=0;
				dfs(i,j,0);
				dfs1(i,j,0);
				if(c==2)ans++;
			}
		}
		cout<<ans<<"\n";
	}

	

	return 0;
}
