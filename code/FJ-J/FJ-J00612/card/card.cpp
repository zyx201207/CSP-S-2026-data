#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
 
int n,m,a[N],b[N],vis[N];
stack<int>st;

signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		//while(!st.empty())st.pop();
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=n;j++){
			if(vis[a[j]]==0){
				st.push(a[j]);
				vis[a[j]]=1;
			}
			else{
				while(st.top()!=a[j]){
					vis[st.top()]=0;
					st.pop();
				}
			}
		}
		while(!st.empty()){
			b[st.top()]++;
			st.pop();
	
		}
		
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	
	return 0;
}
//10:10AC? 
