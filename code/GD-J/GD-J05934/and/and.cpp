#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
#define ll long long
ll n,m,a[maxn],mmax,ppow=2147483647;
void dfs(ll t,ll m,ll num){
	if (m<1) {
		mmax=max(num,mmax);
		return;
	}
	if (t==n+1) return;
	dfs(t+1,m-1,num&a[t]);
	dfs(t+1,m,num);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	dfs(1,m,ppow);
	cout<<mmax;
	return 0;
} 
