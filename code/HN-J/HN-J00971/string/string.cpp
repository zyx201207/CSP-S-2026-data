#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,a[N],b[N];
char c[N];
signed main()
{
 	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	for(int i=n;i>=1;i--)
		b[i]+=b[i+1]+a[i];
	for(int i=1;i<=n;i++)
		a[i]+=a[i-1];
	int l=1,ll=0,r=n,rr=0,ans=0,cnt=0;
	while(l<=r)
	{
		if(a[l]<=cnt)
			l++;
		if(b[r]<=cnt)
			r--;
		if(l>r)
			break;
		if(a[l]>b[r])
		{
			if(c[l]!=c[r])
			{
				ans+=b[r]-cnt;
				cnt=b[r];
			}
			else
				cnt=b[r];
		}
		else
		{
			if(c[l]!=c[r])
			{
				ans+=a[l]-cnt;
				cnt=a[l];
			}
			else
				cnt=a[l];
		}
	}
	cout<<ans;
	return 0;
}
/*
3
2 a
2 b
1 c

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

2
2 a
3 a


2 4 5
5 3 1
l=1 r=3
cnt=1,ans=1
l=1 r=2
cnt=2,ans=1+1
l=2,r=2
cnt=3,ans=2
*/

