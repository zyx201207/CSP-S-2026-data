#include<bits/stdc++.h>
using namespace std;
int a[500005],ans[300005]={0},b[500005];
bool vis[500005]={0};
int n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		stack<int>q;
		for(int j=i;j<=n;j++){
			if(!vis[a[j]]){
				vis[a[j]]=1;
				q.push(a[j]);
				b[a[j]]=j;
			}
			else{
				for(int k=b[a[j]];k<=j-1;k++){
					q.pop();
				}
				q.push(a[j]);
				b[a[j]]=j;
			}
		}
		while(!q.empty()){
			ans[q.top()]++;
			q.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 
