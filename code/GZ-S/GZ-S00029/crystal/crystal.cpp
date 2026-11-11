//GZ-S00029 贵阳市白云区华师一学校 李峈颐
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],cnt1,ans1,opf1,maxx;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal3.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long mj=m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(a[1]==a[n])
	{
		cout<<n;
		return 0;
	}
	cnt1=1;
	m=mj;
	opf1=ans1=0;
	bool f=false;
	for(int i=1;i<=n+1;i++)
	{
		if(a[i]==a[i-1])cnt1++;
		else
		{
			long long op=abs(a[i]-a[i-1]);
			opf1+=cnt1;
			if(i==1)opf1=0;
			else if(m-abs(op*opf1)>=0||m==0)
			{
				m-=abs(op*opf1);
				ans1+=cnt1;
			}
			cnt1=1;
		}
	}
	cout<<ans1;
	return 0;
 } 
