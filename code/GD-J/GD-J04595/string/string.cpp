#include<bits/stdc++.h>
using namespace std;
long long tsq;
int n,a[200001];
char c[200001];
int l,r,ll,rr;
long long ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	l=a[1];
	ll=1;
	r=a[n];
	rr=n;
	while(ll<rr)
	{
		if(c[ll]==c[rr]) {
			if(l<r) {
				ll++;
				r=r-l;
				l=a[ll];
			}
			else if(l>r) {
				rr--;
				l=l-r;
				r=a[rr];
			}
			else if(l==r) {
				ll++;
				rr--;
				l=a[ll];
				r=a[rr];
			}
		}
		else {
			if(l<r)
			{
				ans=ans+l;
				ll++;
				r=r-l;
				l=a[ll];
			}
			else if(l>r) {
				ans=ans+r;
				rr--;
				l=l-r;
				r=a[rr];
			}
			else {
				ans=ans+l;
				ll++;
				rr--;
				l=a[ll];
				r=a[rr];
			}	
		}
	}
	printf("%lld",ans);
	return 0;
}

