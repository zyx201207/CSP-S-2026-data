#include<bits/stdc++.h>
using namespace std;
stack<int> p;
int a[10101010],shu[10101010];
bool vis[10101010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int j=1;j<=n;j++){
		memset(vis,0,sizeof(vis));
		for(int i=j;i<=n;i++){
			
			if(vis[a[i]]==0){
				p.push(a[i]);
				vis[a[i]]=1;
			}
			else{
				while(p.top()!=a[i]){
					vis[p.top()]=0;
					p.pop();
				} 
			}
			
		}
		while(!p.empty()){
			shu[p.top()]++;
			p.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<shu[i]<<' ';
	}
	return 0;
} 
