#include<bits/stdc++.h>
using namespace std;
long long n,m,maxn=-1;
long long arr[100100],brr[100100];
long long p;
bool vis[100100];
void dfs(int cishu){
	if(cishu>m){
		p=brr[1];
		for(long long i=2;i<=m;i++){
			 p=p&brr[i];
		}
		maxn=max(maxn,p);
		return ;
	}
	
	for(long long i=1;i<=n;i++){
		if(!vis[i]){
			brr[cishu]=arr[i];
			vis[i]=1;
			dfs(cishu+1);
			vis[i]=0;
		
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>arr[i];
	}
	dfs(1);
	cout<<maxn;
	return 0;
}

