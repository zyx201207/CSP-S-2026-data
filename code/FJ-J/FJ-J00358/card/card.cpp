#include<bits/stdc++.h>
using namespace std;
int n,m,a[20100],cnt1[20100];
stack<int> st;
bool vis[20100];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
		for(int j=1;j<=n;j++){
			for(int i=j;i<=n;i++){
				if(vis[a[i]]==0){
					st.push(a[i]);
					vis[a[i]]=1;
				}else{
					while(!st.empty()){
						if(st.top()==a[i]){
							st.pop();
							break;
						}
						vis[st.top()]=0;
						st.pop();
					}
					st.push(a[i]);
				}
			}
			while(!st.empty()){
				cnt1[st.top()]++;
				cout<<st.top()<<" ";
				st.pop();
			}
			cout<<endl;
			memset(vis,0,sizeof(vis));
		}
		for(int i=1;i<=m;i++){
			cout<<cnt1[i]<<" ";
		}
	return 0;
}

