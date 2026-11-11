#include<bits/stdc++.h>
using namespace std;
int a[500005];
bool vis[300005];
int ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	stack<int>st;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(vis[a[j]]){
				while(st.top()!=a[j]){
					vis[st.top()]=0;
					st.pop();
				}
				vis[st.top()]=0;
				st.pop();
			}
			vis[a[j]]=1;
			st.push(a[j]);
		}
		while(!st.empty()){
			ans[st.top()]++;
			vis[st.top()]=0;
			st.pop(); 
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
