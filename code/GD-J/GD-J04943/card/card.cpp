#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,a[N],c[N];
bool vis[N];
stack<int>q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	int w=1;
	while(w<=n){
		memset(vis,0,sizeof vis);
		for(int i=w;i<=n;i++){
			if(!vis[a[i]]) q.push(a[i]),vis[a[i]]=1;
			else while((!q.empty())&&(q.top()!=a[i])) vis[q.top()]=0,q.pop();	
		}
		while(!q.empty()){
			c[q.top()]++;
			q.pop();
		}
		w++;
	}
	for(int i=1;i<=m;i++) cout<<c[i]<<' ';
	return 0;
} 
