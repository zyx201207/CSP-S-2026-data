#include <bits/stdc++.h>
using namespace std;
const int maxn=500005;
const int maxm=300005;
//vector<int> ne[maxn];
int a[maxn];
int ans[maxm];
int n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	
	for(int i=1;i<=n;i++){
		bool vis[n+1]={};
		stack<int> st;
		for(int j=i;j<=n;j++){
			if(vis[a[j]]){
				while(!st.empty() && a[j]!=st.top()){
					vis[st.top()]=false;
					st.pop();
				}
				if(!st.empty()) st.pop();
			}
			st.push(a[j]);
			vis[a[j]]=true;
		}
		while(!st.empty()){
			++ans[st.top()];
			st.pop();
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
