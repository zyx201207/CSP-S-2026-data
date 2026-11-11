#include<bits/stdc++.h>
using namespace std;
long long a[999999],maxn=LONG_LONG_MIN;
int n,m;
void dfs(int k,int t,long long sum){
	if(k>n)return;
	if(t<=m&&t!=1)
		sum&=a[k];
	if(t==m){
		maxn=max(sum,maxn);
		return;
	}
	for(int i=1;k+i<=n;i++)
		dfs(i+k,t+1,sum);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
		dfs(i,1,a[i]);
	cout<<maxn<<endl;
	return 0;
}
