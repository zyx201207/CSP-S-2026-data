#include <bits/stdc++.h>
#define int long long
using namespace std;
int l[2000005],r[2000005];
char ch[2000005];
char st[50000005];
int le=0;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int xx;char yy;
		cin>>xx>>yy;
		l[i]=le+1;
		le+=xx;
		r[i]=le;
		ch[i]=yy;
	}
	if (le>5e7)
	{
		int sum=0;
		int i=1,j=le;
		while(i<j)
		{
			int ar1=upper_bound(l+1,l+n+1,i)-l-1;
			int ar2=upper_bound(l+1,l+n+1,j)-l-1;
			int x=r[ar1]-i+1,y=j-l[ar2]+1;
			if (ch[ar1]!=ch[ar2]) sum+=min(x,y);
			if (x==y) 
				i=l[ar1+1],j=r[ar2-1];
			else if (x>y)
			{
				i=l[ar1]+j-r[ar2-1];
				j=r[ar2-1];
			}
			else
			{
				j=r[ar2]-(r[ar1]-i+1);
				i=l[ar1+1];
			}
		}
		cout<<sum;
		return 0;
	}
	for(int i=1;i<=n;i++)
		for(int j=l[i];j<=r[i];j++) st[j]=ch[i];
	int ll=1,rr=le,ss=0;
	while(ll<=rr)
	{
		if (st[ll]!=st[rr]) ss++;
		ll++;rr--;
	}
	cout<<ss;
	return 0;
}
