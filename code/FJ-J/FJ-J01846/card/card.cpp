#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
long long ans[300005];
stack<int> st;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int vis[300005]={};
		for(int j=i;j<=n;j++){
			while(vis[a[j]]){
				vis[st.top()]=0;
				st.pop();
			}
			vis[a[j]]=1;
			st.push(a[j]);
		}
		while(!st.empty()){
			ans[st.top()]++;
			st.pop();
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
