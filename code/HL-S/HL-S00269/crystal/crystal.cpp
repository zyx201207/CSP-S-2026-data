#include <bits/stdc++.h>
using namespace std;
const long long N=500005;
long long n,m,a[N];
int main ()
	{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	long long ans=-1,sum=0,m_=m; //ans the last ,sum the new one
	for (int i=n;i>=1;i--)//i为当前合成阈值 
		{
		sum=1;m_=m;
		if (ans>i) break;
		for (int j=i-1;j>=1;j--) //j为下一个可以被利用的rock 
			{
			//cout<<i<<" "<<j<<" "<<a[i]<<" "<<a[j]<<" / ";
			if (a[i]-a[j]<=m_)
				{
				m_-=(a[i]-a[j]);
				sum++;
				//cout<<m_<<" "<<sum<<endl;
				}
			else break;
			}
		if (sum>ans) ans=sum;
		}
	cout<<ans;
	return 0;
	}
