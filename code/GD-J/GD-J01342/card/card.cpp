#include<bits/stdc++.h>
#include<stack>
using namespace std;
int n,m,a[500005],vis[300005],ans[300005];
stack<int>st;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=0;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(vis[a[j]]>=1){
				while(st.top()!=a[j]){
					vis[st.top()]--;
					st.pop();
				}
				vis[st.top()]--;
				st.pop();
			}
			st.push(a[j]);
			vis[a[j]]++;
		}
		st.empty();
		for(int j=1;j<=m;j++){
			ans[j]+=vis[j];
			vis[j]=0;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
