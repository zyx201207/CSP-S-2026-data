#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],tong[500005];
bool vis[300005];
stack<int> stk;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(vis[a[j]]==false){
				stk.push(a[j]);
				vis[a[j]]=true;
			}
			else {
				while(stk.top()!=a[j]){
					vis[stk.top()]=false;
					stk.pop();
				}
			}
		}
		while(!stk.empty()){
			tong[stk.top()]++;
			stk.pop();
		}
		for(int j=1;j<=300005;j++)vis[j]=false;
	}
	for(int i=1;i<=m;i++)cout<<tong[i]<<" ";
	return 0;
}
