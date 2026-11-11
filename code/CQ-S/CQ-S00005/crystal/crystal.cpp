#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans=0,idx=1,a[500001],sum[500001]; 
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){//¹Ì¶¨iÎªÓÒÖ¸Õë 
		while(a[i]*(i-idx)-sum[i-1]+sum[idx-1]>m) idx++;
		ans=max(ans,i-idx+1); 
	}
	cout<<ans<<"\n";
	
	return 0;
}
/*
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7
*/ 
