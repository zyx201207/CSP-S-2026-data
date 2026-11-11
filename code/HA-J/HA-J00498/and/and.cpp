#include<bits/stdc++.h>
#define int long long
using namespace std;
struct usn{
	int id,cnt,m;
}tot[300010];
int a[300010];
bool cmp(usn a,usn b)
{
	if(a.cnt==b.cnt)
	{
		return a.m>b.m;
	}
	return a.cnt>b.cnt;

}
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int sum=0,mx=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i>1) sum&=a[i];
		else sum=a[i];
		mx=max(mx,a[i]);
	}
	if(m==1) cout<<mx;
	else if(m==n) cout<<sum;
	else if(m==2)
	{
		int mxx=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				int ret=a[i]&a[j];
				if(ret>mxx)
				{
				//	cout<<a[i]<<" "<<a[j]<<" "<<ret<<"\n";
					mxx=ret;
				}
			}
		}
		cout<<mxx;
	}
	else if(m==n-1)
	{
		sort(a+1,a+1+n);
		sum=a[2];
		for(int i=3;i<=n;i++)
		{
			sum&=a[i];
		}
		cout<<sum;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			int k=a[i];
			tot[i].id=i;
			tot[i].m=a[i];
			while(k!=0)
			{
				if(k%2==1) tot[i].cnt++;
				k/=2;
			}
		}
		sort(tot+1,tot+1+n,cmp);
		sum=a[tot[1].id];
	//	cout<<tot[1].id<<" ";
		for(int i=2;i<=m;i++)
		{
		//	cout<<tot[i].id<<"\n";
			sum&=a[tot[i].id];
		}
		cout<<sum;
	}
	return 0;
}
