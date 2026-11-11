#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const int M=3e5+10;
int a[N];
int ans[M];
stack<int>st;
bool vis[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof vis);
		
		for(int j=i;j<=n;j++){
			int now=a[j];
			if(vis[now]){
				while(st.top()!=now&&!st.empty()){
					vis[st.top()]=0;
					st.pop();
				}
			}
			else{
				vis[now]=1;
				st.push(now);
			}	
		}
		while(!st.empty()){
			ans[st.top()]++;
			st.pop();
		}
	}
	for(int i=1;i<=m;i++)cout<<a[i]<<" ";
	return 0;
}
