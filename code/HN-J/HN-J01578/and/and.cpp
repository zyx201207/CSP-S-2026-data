#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,m;
long long a[N],ans;
void dfs(long long sum,long long mx,long long i){
	if(sum==m){
		ans=max(ans,mx);
		return ;
	}
	if(i==n)return ;
	dfs(sum+1,mx&a[i],i+1);
	dfs(sum,mx,i+1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)cin>>a[i];
	if(n<=2000){
		for(long long i=1;i<=n-m;i++){
			dfs(1,a[i],i+1);
		}
	}else{
		sort(a+1,a+1+n);
		ans=a[n];
		for(long long i=n-1;i>n-m;i--)ans=ans&a[i];
	}
	cout<<ans;
	return 0;
}

