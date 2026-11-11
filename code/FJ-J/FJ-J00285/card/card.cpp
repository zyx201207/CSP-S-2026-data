#include<bits/stdc++.h>
using namespace std;
int n,m;
int f;
int a[500005];
int last[500005];
int v[300005];
int vis[500005];
int x[300005];
int dp[500005];
void find(int p){
	if(p==0)return ;
	x[p]=1;
	dp[last[p]]=dp[p];
	find(last[p]);
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]){
			f=1;
		}
	}if(f==0){
		for(int i=1;i<=n;i++){
			if(a[i+1]>a[i]){
				cout<<i<<' ';
			}
		}cout<<n;
		return 0;
	}if(m==2){
		for(int i=1;i<=n;i++){
			v[a[i]]++;
		}
		for(int i=1;i<=m;i++){
			if(a[n]==i){
				cout<<n;
			}else{
				cout<<v[i];
			}
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(vis[a[i]]!=0){
			last[i]=vis[a[i]];
		}vis[a[i]]=i;
	}dp[n]=a[n];
	int s=a[n]; 
	for(int i=n;i>=1;i--){
		if(dp[i]==0){
			dp[i]=dp[i+1]*10+a[i];
		}
		if(x[i]==0){
			find(i);
		}
	}
	for(int i=1;i<=n;i++){
		while(dp[i]){
			v[dp[i]%10]++;
			dp[i]/=10;
		}
	}for(int i=1;i<=m;i++){
		cout<<v[i]<<' ';
	}
	return 0;
}
