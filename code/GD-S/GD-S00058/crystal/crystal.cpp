#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+5;
long long n,m,a[N],sum,ans;
bool flag=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i],sum+=a[i];
	sum/=n;	
	for(int i=1;i<=n;i++)if(sum>=a[i])a[i]=sum-a[i];else a[i]=1e18;
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)if(a[i]<=m)ans++,m-=a[i];else break;
	cout<<ans;
	return 0;
}
