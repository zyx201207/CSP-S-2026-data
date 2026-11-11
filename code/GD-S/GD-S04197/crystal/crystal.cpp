#include<bits/stdc++.h>
using namespace std;
int n;
long long cnt,temp;
long long a[500005];
long long sum[500005],pre[500005];
long long m;
long long ans;
int l,r;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		sum[i]=(long long)a[i]-a[i-1];
	}
	l=1,r=2;
	while(l<=n && r<=n){
		if(temp+cnt*sum[r]<=m){
			cnt++;
			temp+=cnt*sum[r];
			r++;
		}
		else{
			ans=max(ans,cnt);
			cnt--;
			temp-=(a[r-1]-a[l-1]);
			l++;
		}
	}
	printf("%lld",ans+1);
	return 0;
 } 
