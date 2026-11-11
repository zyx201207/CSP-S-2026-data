#include<bits/stdc++.h>
using namespace std;
int n,m;
stack<int> st;
bool vis[1000005],flag1=1;
int a[1000005],sum[1000005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	a[0]=-1000000;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]) flag1=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(vis[a[j]]==1){
				while(1){
					int s=st.top();
					if(s==a[j]) break;
					else{
						st.pop();
						vis[s]=0;
					}
				}
			}else{
				vis[a[j]]=1;
				st.push(a[j]);
			}
			//for(int k=1;k<=m;k++) cout<<vis[k]<<" ";
			//cout<<endl;
			}
		while(!st.empty()){
			sum[st.top()]++;
			//cout<<st.top()<<" ";
			st.pop();
		}
		//cout<<endl;
		memset(vis,0,sizeof(vis));
	}
	for(int i=1;i<=m;i++) cout<<sum[i]<<" ";
	return 0;
} 
