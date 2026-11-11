#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200005],ans,cnt,sum,l[200005],r[200005],idl,idr,k[200005],id;
char c[200005],lc[200005],rc[200005];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		cnt+=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		sum+=a[i];
		if(sum<=cnt/2)
		{
			l[++idl]=a[i];
			lc[idl]=c[i];
		}
		else
		{
			int t=sum-(cnt+1)/2;
			id=i+1;
			l[++idl]=a[i]-t;
			lc[idl]=c[i];
			r[0]=t;
			rc[0]=c[i];
			break;
		}
	}
	for(int i=n;i>=id;i--)
	{
		r[++idr]=a[i];
		rc[idr]=c[i];
	}
	r[++idr]=r[0];
	rc[idr]=rc[0];
	if(cnt%2==1)
		ans--;
	int i=1,j=1;
	while(i<=idl&&j<=idr)
	{
		if(lc[i]==rc[j])
		{
			if(l[i]>r[j])
			{
				l[i]-=r[j];
				j++;
			}
			else if(l[i]<r[j])
			{
				r[j]-=l[i];
				i++;
			}
			else
			{
				i++;
				j++;
			}
		}
		else
		{
			if(l[i]>r[j])
			{
				ans+=r[j];
				l[i]-=r[j];
				j++;
			}
			else if(l[i]<r[j])
			{
				ans+=l[i];
				r[j]-=l[i];
				i++;
			}
			else
			{
				ans+=l[i];
				i++;
				j++;
			}
		}
	}
	while(i<=idl)
	{
		ans+=l[i];
		i++;
	}
	while(j<=idr)
	{
		ans+=r[j];
		j++;
	}
	cout<<ans;
	return 0;
}
