#include<bits/stdc++.h>
using namespace std;
queue <int>q;
int  n,m,a[501010],ans[310101],vis[501010];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		if(vis[a[i]]==0){
			q.push(a[i]);
			vis[a[i]]=1;
		}else{
			while(q.front()!=a[i]){
				int x=q.front();
				q.pop();
				q.push(x);
			}
			q.pop();
			while(q.front()!=a[i]){
				vis[q.front()]=0;
				q.pop();
			}
		}
		int xx=q.front();
		a[xx]++; 
		q.pop();
		while(q.front()!=xx){
			int x=q.front();
			ans[x]++;
			q.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
} 
