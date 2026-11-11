#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
ll a[N],vis[N],n,m,maxn;
void dfs(int k,ll sum){
	if(k>m){
		maxn=max(maxn,sum);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(k+1,(sum&a[i]));
			vis[i]=0; 
		}
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1){
		for(int i=1;i<=n;i++) maxn=max(maxn,a[i]);
		cout<<maxn<<'\n';
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				maxn=max(maxn,(a[i]&a[j]));
			}
		}
		cout<<maxn<<'\n';
	}else{
		for(int i=1;i<=n;i++){
			vis[i]=1;
			dfs(2,a[i]);
			vis[i]=0;
		}
		cout<<maxn<<'\n';
	}
	return 0;
}
/*
为什么赛场里有蜜蜂 
*/
