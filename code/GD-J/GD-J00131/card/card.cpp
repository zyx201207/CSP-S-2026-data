#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,a[500010],ans[300010],vis[300010];
stack<int> q;
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
		for(int j=1;j<=m;j++){
			vis[j]=0;
		}
		while(!q.empty()){
			q.pop();
		}
		for(int j=i;j<=n;j++){
			if(vis[a[j]]){
				while(!q.empty()){
					int k=q.top();
					q.pop();
					vis[k]=0;
					if(k==a[j]){
						break;
					}
				}
			}
			vis[a[j]]=1;
			q.push(a[j]);
		}
		while(!q.empty()){
			int k=q.top();
			q.pop();
			ans[k]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 
