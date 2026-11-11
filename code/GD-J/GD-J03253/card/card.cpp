//time is limited.........
#include<iostream>
#include<stack>
using namespace std;
int n,m,a[500005],ans[300005];
bool vis[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		stack<int> q;
		fill(vis+1,vis+1+m,0);
		for(int j=i;j<=n;j++){
			if(!vis[a[j]]) q.push(a[j]),vis[a[j]]=1;
			else while(q.top()!=a[j]) vis[q.top()]=0,q.pop();	
		}
		while(!q.empty()) ans[q.top()]++,q.pop();
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1


*/
