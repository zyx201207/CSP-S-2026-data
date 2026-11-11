#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+1];
	for(int i(0);i<n;i++)cin>>a[i];
	queue<int>table;
	bool vis[n+1]={};
	int ans[m+1]={};
	for(int i(0);i<n;i++){
		while(!table.empty())table.pop();
		memset(vis,0,sizeof(vis));
		for(int j(i);j<n;j++){
			if(vis[a[j]]!=0){
				int temp,t=0;
				while(table.front()!=a[j]){
//					cout<<table.front()<<" ";
					table.push(table.front()),table.pop(),t++;
				}
//				cout<<'\n';
				temp=table.size()-t;
				while(temp--){
//					cout<<table.front()<<" ";
					vis[table.front()]=0,table.pop();
				}
//				cout<<'\n';
			}
			table.push(a[j]),vis[a[j]]=1;
		}
		for(int j(1);j<=m;j++){
			if(vis[j]!=0)ans[j]++;
		}
	}
	for(int i(1);i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
} 
