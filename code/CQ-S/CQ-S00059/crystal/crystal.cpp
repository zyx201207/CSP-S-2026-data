#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long a[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		//cerr<<a[i]<<' ';
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=2;i--)
	{
		a[i]-=a[i-1];
	//	cerr<<a[i]<<' ';
	}
//	for(int i=2;i<=n;i++)
//	{
//		cerr<<a[i]<<' ';
//	}
	//cerr<<a[1];
	//cerr<<'\n';
	if(m==0)
	{
		int maxx=0,pt=0;
		for(int i=2;i<=n;i++)
		{
			if(a[i]==0)
			{
				pt++;
			}
			else
			{
				maxx=max(maxx,pt);
				pt=0;
			}
		}
		maxx+=1;
		cout<<maxx;
		return 0;
	}
	long long maxx=0;
	for(long long nt=2;nt<=n-maxx;nt++)
	{
		if(nt!=2&&a[nt]==0)
		{
			continue;
		}
		bool bo=0;
		long long jz=0;
		for(long long i=nt;i<=n;i++)
		{
			if(a[i]==0)
			{
				continue;
			}
			//cerr<<a[i]*(i-1)<<' '<<m-jz<<'\n';
			//cerr<<jz<<'\n';
			if(a[i]*(i-nt+1)>m-jz)
			{
	//			for(int j=i+1;j<=n;j++)
	//			{
	//				if(a[j]!=0)
	//				{
	//					cerr<<j-1<<'\n';
	//					break;
	//				}
	//			}
				maxx=max(maxx,i-nt+1);
				bo=1;
				break;
			}
			else
			{
				jz+=a[i]*(i-nt+1);
			}
		}
		if(bo==0)
		{
			maxx=max(maxx,n-nt+2);
		}
	}
	cout<<maxx;
	return 0;
}
