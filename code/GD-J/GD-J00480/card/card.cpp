#include<bits/stdc++.h>
using namespace std ;
int n;
int m;
long long a[500010];
long long sum[300010];
bool vis[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		stack<long long> q;
		for(int j=1;j<=m;j++){
			vis[j]=0;
		}
		for(int k=i;k<=n;k++){
			if(vis[a[k]]==1){
				while(!q.empty()){
					if(q.top()==a[k]){
						q.pop();
						break;
					}
					vis[q.top()]=0;
					q.pop();
				}
				
			}
			q.push(a[k]);
			vis[a[k]]=1;
		}
		for(int j=1;j<=m;j++){
			if(vis[j]){
				sum[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<" ";
	}
	return 0;
}
