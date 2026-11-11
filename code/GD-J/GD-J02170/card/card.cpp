#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N],ans[N];
bool vis[N];
stack<int> q;
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
	for(int i=1;i<=n;i++){
		for(int d=1;d<=m;d++) vis[d]=0;
		while(!q.empty()) q.pop();
		for(int j=i;j<=n;j++){
			if(vis[a[j]]){
				while(q.top()!=a[j]){
					vis[q.top()]=0;
					q.pop();
				}
			}
			else{
				q.push(a[j]);
				vis[a[j]]=1;
			}
		}
		while(!q.empty()){
			ans[q.top()]++;
			q.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}

