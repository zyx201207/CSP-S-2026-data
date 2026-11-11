#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m;
int a[N];
int ans[N];
bool vis[N];
stack<int> q;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		
		for(int j=1;j<=m;j++) vis[j]=0;
		
		for(int j=i;j<=n;j++){
			if(vis[a[j]]==1){
				while(q.size()){
					int x=q.top();
					q.pop();
					vis[x]=0;
					if(x==a[j]) break;
				}
			}
			vis[a[j]]=1;
			q.push(a[j]);
		}
		while(q.size()){
			int x=q.top();
//			cout<<x<<' ';
			q.pop();
			ans[x]++;
		}
//		cout<<'\n';
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
/*
4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1
*/
