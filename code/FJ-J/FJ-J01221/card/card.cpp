#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
const int Max=5e5+5;
int n,m;
int a[Max],ans[Max];
bool vis[Max];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(vis,false,sizeof(vis));
		stack<int >st;
		for(int j=i;j<=n;j++){
			if(vis[a[j]]==false){
				st.push(a[j]);
				vis[a[j]]=true;
			}
			else {
				while(st.top()!=a[j]){
					int t=st.top();
					st.pop();
					vis[t]=false;
				}
			}
		}
		while(!st.empty()){
			int t=st.top();
			st.pop();
			ans[t]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}
/*
100 + 100 + 40 + 40 = 280
luogu id : xu01
*/

