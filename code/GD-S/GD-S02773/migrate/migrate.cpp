#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=50005;
int c,t;
int x[N];
bool vis[N];
int mn=1e9,step;
int n,d;
void dfs(int xx,int dd,int str,int last){
	if(xx==dd){
		if(str<mn){
			step=1;
			mn=str;
		}else if(str==mn){
		//	cout<<xx<<"\n";
			step++;
		}
		return ;
	}
	if(str>mn)return ;
//	if(xx<=dd-1)dfs(xx+1,dd,str+1,last);
	for(int i=xx+1;i<=n;i++){
		if(abs(x[xx]-x[i])<=d)dfs(i,dd,str+1,last);
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				memset(vis,0,sizeof(vis));
				step=1;
				mn=1e9;
				dfs(i,j,0,i);
				if(step==2){
			//		cout<<i<<" "<<j<<" "<<mn<<"\n";
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
}
/*

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5





0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6


*/
