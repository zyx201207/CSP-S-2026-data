#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],l,cnt,ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n%2!=0) l=n/2+1;
	else l=n/2;
	for(int i=l;i<=n;i++)
	{
		cnt=0;
		for(int j=l;j>=1;j--)
		{
			b[j]=a[l]-a[j];
			cnt+=b[j];
			if(cnt>m) 
			{
				l--;
				break;
			}
		}
		if(cnt<=m) 
		{
			ans=l;
			l++;
		}
	}
	cout<<ans;
	return 0;
}
