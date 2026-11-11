#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,a[N],sum[N],maxn=1;
int main () {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int s=a[1];
	for(int i=1;i<=n;i++)a[i]-=s;
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
    long long i=1;
    for(long long j=1;j<=n;j++){
    	long long ans=a[j]*(j-i+1)-(sum[j]-sum[i-1]);
    	if(ans>m)i++;
    	else maxn=max(maxn,j-i+1);
	}
	cout<<maxn;
	return 0;
}
