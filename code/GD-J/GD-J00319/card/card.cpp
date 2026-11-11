#include<bits/stdc++.h>
using namespace std;
int card[500005],vis[300005],dp[300005];
queue<int> q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>card[i];
	}
	for(int i=1;i<=n;i++){
		while(!q.empty())q.pop();
		for(int i=1;i<=m;i++){
			vis[i]=0;
		}
		for(int j=i;j<=n;j++){
			if(vis[card[j]]==0){
				q.push(card[j]);
				vis[card[j]]=1;
			}else{
				while(q.front()!=card[j]){
					vis[q.front()]=0;
					q.pop();
				}
			}
		}
		for(int j=1;j<=m;j++){
			dp[j]+=vis[j];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<dp[i]<<' ';
	}
	return 0;
} 
