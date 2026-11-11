#include <bits/stdc++.h>
using namespace std;
int n,a[200005];
long long cnt;
char b[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
	if(n==2&&a[1]+a[2]==2)
	{
		cout<<(b[1]!=b[2]?1:0);
		return 0;
	}
	if(n==1)
	{
		cout<<0;
		return 0;
	}
	int l=1,r=a[n];
	int p1=1,p2=n;
	while(!(p1==p2&&r-l<=1||p2-p1==1&&(l==a[p1]&&r==1)))
	{
		if(b[p1]!=b[p2]) cnt++;
		l++;
		r--;
		if(l>a[p1])
		{
			p1++;
			l=1;
		}
		if(r<1)
		{
			p2--;
			r=a[p2];
		}
	}
	cout<<cnt;
	return 0;
}
