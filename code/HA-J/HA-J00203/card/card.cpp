#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],vis[500005],book[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	int stemp=0;
	for(int g=0;g<n;g++){
		stack<int>st;
		memset(vis,0,sizeof(vis));
		for(int i=stemp;i<n;i++){
			if(vis[a[i]]==1){
				while(!st.empty()) st.pop();
				st.push(a[i]);
			}if(vis[a[i]]==0){
				vis[a[i]]=1;
				st.push(a[i]);
			}
		}
		for(int i=0;i<st.size();i++){
			book[st.top()]++;
			st.pop();
		}stemp++;
	}for(int i=0;i<m;i++) cout<<book[i]<<" ";
	return 0;
}
