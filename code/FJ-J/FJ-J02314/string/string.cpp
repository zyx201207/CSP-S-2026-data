#include <bits/stdc++.h>
using namespace std;
const long long N=2e5+12;
long long n,a[N],ans,len,tem;//tem :back cnt n
char c[N];
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		len+=a[i];
	}
	len/=2;
	//len/=2 len-=min(a[i],len)until len==0
	for(int l=1,r=n+1;;)
	{
		if(len==0)break;
		a[l]=min(len,a[l]);
		len-=min(a[l],a[r]);
		tem=min(a[l],a[r]);
		if(c[l]!=c[r])ans+=tem;
		a[l]-=tem;
		a[r]-=tem;
		if(a[l]==0) l++;
		if(a[r]==0) r--;
	}
	cout<<ans;
	return 0;
}
