#include<bits/stdc++.h>
using namespace std;
bool vis[500010];
int ju[500010];
int pai[500010];
stack<int> s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>pai[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(vis[pai[j]]==0){
				vis[pai[j]]=1;
				s.push(pai[j]);
			}	
			else{
				int x=0;
				while(1){
					x=s.top();
					vis[x]=0;
					s.pop();
					if(x==pai[j]){
						break;
					}
				}
				vis[pai[j]]=1;
				s.push(pai[j]);
			}
		}
		for(int j=1;j<=m;j++){
			if(vis[j]==1){
				ju[j]++;
			}
		}
		memset(vis,0,sizeof(vis));
		while(!s.empty()){
			s.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ju[i]<<" ";
	}
	return 0;
}
