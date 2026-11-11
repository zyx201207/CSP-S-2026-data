//GZ-J00439 贵阳市第一中学 徐錦鴻 
#include<bits/stdc++.h>
using namespace std;
int n,m,r=1,rr=1,a[500005],maxn;
void dfs(int i,int k,int sum){
	if(k==m){
		maxn=max(sum,maxn);
		return ;
	}
	if(i>n) return ;
	dfs(i+1,k+1,(sum&a[i]));
	dfs(i+1,k,sum);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(n&(n+1)) r=0;
		if(rr!=i-1) rr=0;
	} 
	if((!(n&(n-1))&&rr)||r){
		sort(a+1,a+n+1);
		maxn=a[n];
		for(int i=n-1;i>=n-m+1;i++) maxn=(maxn&a[i]); 
		cout<<maxn;
		return 0;
	}
	for(int i=1;i<=n;i++) dfs(i+1,1,a[i]);
	cout<<maxn;
	return 0;
}
