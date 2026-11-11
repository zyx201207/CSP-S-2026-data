#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,a[N],c,maxn=1,tail=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	c=m;
	for(int i=2;i<=n;i++)
	{
		//cout<<tail<<" "<<c<<endl;
		while(1)
		{
			if(c-(i-tail)*(a[i]-a[i-1])>=0) break;
			c+=a[i-1]-a[tail];
			tail++;
		}
		c-=(i-tail)*(a[i]-a[i-1]);
		maxn=max(i-tail+1,maxn);
	}
	cout<<maxn;
	return 0;
}
