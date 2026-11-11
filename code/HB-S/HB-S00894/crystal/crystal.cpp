#include<bits/stdc++.h>
using namespace std;
int n,m;
int ans=0;
int a[500005],cnt[500005],sum[500005];
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
cin>>n>>m;
int a[n];
for(int i=0;i<n;i++)
	cin>>a[i];
sort(a+1,a+n+1);
for(int i=1;i<=n;i++)
cnt[i]=a[i]*i,sum[i]=sum[i-1]+a[i];
for(int i=2;i<=n;i++){
	int a=0;
	while(sum[i]-sum[a]+m<cnt[i] and a<i) a++;
	ans=max(ans,i-a);
}
cout<<ans+1<<endl;
return 0;
}
