#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+100;
long long n,m,a[N]; 
long long pre[N],v[N],w[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		pre[i]=pre[i-1]-a[i];
	}
	long long count=0;
	for(long long i=1;i<=n;i++){
		for(long long j=i;j<=n;j++){
			count++;
			w[count]=a[i+j-1]*i-(pre[i+j-1]*pre[j-i]); 
			v[count]=j-i+1;
		}
	}
	long long ans=-100000000000;
	for(long long i=1;i<=count;i++){
		if(w[i]<=m)ans=max(ans,v[i]);
	}
	cout<<ans;
	return 0;
}
