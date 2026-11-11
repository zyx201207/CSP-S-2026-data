#include<bits/stdc++.h>
using namespace std;
long long a[500010],presum[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,ans=1;
	long long m;
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",a+i);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		presum[i]=presum[i-1]+a[i];
	for(int i=2;i<=n;i++){
		int l=0,r=i;
		while(l+1<r){
			int mid=l+r>>1;
			if(a[i]*(long long)((i-1)-mid+1)-(long long)(presum[i-1]-presum[mid-1])<=m)
				r=mid;
			else
				l=mid;
		}
		ans=max(ans,i-r+1);
	}
	printf("%d",ans);
	return 0;
} 
