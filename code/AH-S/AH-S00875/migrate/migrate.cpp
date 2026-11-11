#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5005;
int dp[N],sum[N],a[N],d[N];
signed main(){
freopen("migrate.in","r",stdin);
freopen("migrate.out","w",stdout);
ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int n,t,dd;
cin>>t>>t;
while(t--){
	int summ=0;
cin>>n>>dd;
for(int i=1;i<=n;i++) {cin>>a[i];
	sum[i]=a[i];
	}
for(int k=1;k<=n;k++){
	for(int i=1;i<=n;i++) a[i]=0,d[i]=0;
	a[k]=1,d[k]=0;
	d[k-1]=1e18;
for(int i=k+1;i<=n;i++)
{
	//	d[i]=1e18;
    for(int j=i-1;(sum[i]-sum[j])<=dd&&j>=k;j--) {
		if(d[j]<d[j+1]) a[i]=0;
		d[i]=d[j]+1;
	     a[i]+=a[j];
	     a[i]=min(a[i],3LL);
	}
	//cout<<d[i]<<' ';
    if(a[i]==2) summ++;
}
}
//cout<<'\n';
cout<<summ<<'\n';
}
return 0;
} 
