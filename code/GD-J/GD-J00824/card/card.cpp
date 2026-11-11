#include<bits/stdc++.h>
using namespace std;
bool vis[10000000];
int a[10000000],b[10000000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int s=1;
	int t=n;
	while(t--){
		stack<int>st;
		memset(vis,0,sizeof(vis));
		for(int i=s;i<=n;i++){
			if(!vis[a[i]]){
				st.push(a[i]);
				vis[a[i]]=1;
			}else{
				int fl=1;
				while(fl){
					int t=st.top();
					st.pop();
					vis[t]=0;
					if(t==a[i]){
						fl=0;
					}
				}
				st.push(a[i]);
				vis[a[i]]=1;
			}
		}
		while(!st.empty()){
			int t=st.top();
			st.pop();
			b[t]++;
		}
		s++;
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
