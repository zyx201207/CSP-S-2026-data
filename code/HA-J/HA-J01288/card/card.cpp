#include<bits/stdc++.h>
//#define int long long
#define endl "\n"
using namespace std;
//deque<int> q;
int n,m,a[300030],ans[300050];
bool vis[300030];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		stack<int> v;
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=n;j++){
			if(!vis[a[j]]){
				v.push(a[j]);
				vis[a[j]]=1;
			}
			else{
				while(v.top()!=a[j]){
					vis[v.top()]=0;
					v.pop();
				}
			}
		}
		for(int j=1;j<=m;j++){
			ans[j]+=vis[j];
//			cout<<vis[j]; 
		}
//		cout<<endl;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
/*

*/
