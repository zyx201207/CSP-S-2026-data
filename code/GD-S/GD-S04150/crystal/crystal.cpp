#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long int n,m;
	cin>>n>>m;
	long long int a[n+5];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int maxx=-1;
	for(int i=1;i<=n;i++)
	{
		long long int cha[n+5];
		int cnt=0;
		for(int j=1;j<=n;j++)
		{
			if(j!=i)
			{
				int temp=a[i]-a[j];
				cha[cnt]=temp;
				cnt++;
			}
		}
		sort(cha,cha+cnt);
		int num=0,sum=0,m2=m;
		while(m2>=0&&num<cnt)
		{
			bool b=false;
			if(cha[num]>=0) m2-=cha[num],b=true;
			num++;
			if(m2>=0&&b)
			{
				sum++;
			}
		}
		maxx=max(maxx,sum+1);
	}
	cout<<maxx;
	return 0;
}
