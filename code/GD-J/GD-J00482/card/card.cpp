#include<bits/stdc++.h>
using namespace std;
int a[500005],s[300005],vis[300005];
stack<int>st;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=n;j++){
			if(vis[a[j]]>0){
				while(st.top()!=a[j]){
					vis[st.top()]--; 
					st.pop();
				}
			}else{
				st.push(a[j]);
				vis[a[j]]++;
			}
		}
		while(!st.empty()){
			s[st.top()]++;
			st.pop();
		}
	}
	for(int i=1;i<=m;i++)cout<<s[i]<<" ";
	return 0;
}

