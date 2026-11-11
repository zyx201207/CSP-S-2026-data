#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m;
int a[N],vis[N],t[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		stack<int> q;
		memset(vis,0,sizeof vis);
		for(int j=i;j<=n;j++){
			if(vis[a[j]]!=0){
				while(q.top()!=a[j]){
					vis[q.top()]=0;
					q.pop();
				}
				q.pop();
			}
			vis[a[j]]=1;
			q.push(a[j]);
		}
		while(!q.empty()){
			t[q.top()]++;
			q.pop();
		}
 	}
 	for(int i=1;i<=m;i++){
 		cout<<t[i]<<" ";
	}
	return 0;
}
