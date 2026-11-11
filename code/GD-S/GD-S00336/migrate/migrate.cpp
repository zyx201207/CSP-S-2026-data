#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N=2e6+9;
const int inf=0x3f3f3f3f;
int n,d,cnt=0,len=inf;
int vis[N],a[N];
int dfs(int x,int y,int step,int cnt){
	if(x==y){
		if(step<len){
			cnt=1;
		}
		if(step==len){
			cnt++;
		}
		return cnt;
	}
	vis[x]=1;
	for(int i=1;i<=n;i++){
		if(a[i]==x) continue;
		if(abs(a[i]-a[x])<=d&&!vis[i]) return dfs(a[i],y,step+1,cnt);
	}
	vis[x]=0;
}
signed main(){
	//freopen("migrate.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				memset(vis,0,n);
				cnt=0;
				len=inf;
				if(dfs(a[i],a[j],0,0)==2){
					ans++;
				}
			}
		} 
		cout<<ans<<endl;
	}
	
	return 0;
}
