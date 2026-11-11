#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+100;
int n,ans;
ll a[N],m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld ",&a[i]);
	
	sort(a+1,a+n+1);
	int l=0,r=1;
	ll sum=a[1];
	while(l<=r){
		while(r+1<=n&&abs(a[r+1]*(r-l)-sum)<=m){
			r++,sum+=a[r];
		}
		ans=max(ans,r-l);
		l++;
		sum-=a[l];
		if(l==r&&r<n)sum=a[++r];
	}
	printf("%d",ans);
	return 0;
}
