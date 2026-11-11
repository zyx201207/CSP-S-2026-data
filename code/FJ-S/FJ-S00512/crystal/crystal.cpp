#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500010];
int ans=0;
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
scanf("%d%lld",&n,&m);
for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
sort(a+1,a+1+n);
int l=1,r=2,sum=0;
while(l<=r&&l<=n&&r<=n){
	
	if(sum<=m)
	{
	ans=max(ans,r-l+1);
	r++;
	sum+=(a[r]-a[r-1])*(r-l);
	}
	else{
		sum-=(a[r]-a[l]);
		l++;
	}
}
printf("%d",ans);
return 0;
}

