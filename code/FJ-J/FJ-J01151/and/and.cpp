#include"bits/stdc++.h"
using namespace std;
int n,m,maxn=INT_MIN,a[200005];
bool teshuA=1,teshuB=0; 
void dfs(int sum,int xb,int zhi){
	if(zhi<=maxn)return;
	if(sum==0){
		maxn=max(maxn,zhi);
		return;
	}
	for(int i=xb;i<=n;i++){
		dfs(sum-1,i+1,zhi&a[i]);
	}
}
int main(){
	//60 
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<=20;i++){
		if(pow(2,i)==n)
		teshuB=1;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		bool y=0;
		for(int j=0;j<=20;j++){
			if(pow(2,1)-1==a[i])
			y=1;
		}
		if(!y)teshuA=0;
	}
	if(teshuA){
		sort(a+1,a+n+1);
		cout<<a[n+1-m];
		return 0;
	}
	if(teshuB){
		sort(a+1,a+n+1);
		if(m>n/2)cout<<0;
		else cout<<n-m;
		return 0;
	}
	for(int i=1;i<=n;i++){
		dfs(m,i,a[i]);
	}
	cout<<maxn;
	return 0;
}
