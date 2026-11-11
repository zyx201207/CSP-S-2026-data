#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[500050];
int ans[300030];
bool vis[300030],gt[300030];
stack<int> s;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int i=1;i<=n;i++){//第i局 
	memset(vis,false,sizeof(vis));
	memset(gt,false,sizeof(gt));
		for(int j=i;j<=n;j++){//第j张牌 
			if(vis[a[j]]==true){
				while(s.size()!=1&&s.top()!=a[j]){
					s.pop();
				}
				s.pop();
				s.push(a[j]);
			}
			else{
				s.push(a[j]);
				vis[a[j]]=true;
			}
		}
		while(!s.empty()){
			int w=s.top();
			if(gt[w]==false){
				ans[w]++;
				gt[w]=true;
			}
			s.pop();
		}
		while(!s.empty()) s.pop();
	}
	
	for(int i=1;i<m;i++){
		cout<<ans[i]<<" ";
	}
	cout<<ans[m]<<'\n';
	
	return 0;
} 
