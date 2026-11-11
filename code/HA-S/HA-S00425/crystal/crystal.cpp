#include<bits/stdc++.h>
using namespace std;
long long a[100005],b[100005];
bool cmp(int x,int y)
{
	return x<y;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,ans=0,sum=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	} 
	sum/=n;
	for(int i=1;i<=n;i++)
	{
		b[i]=abs(a[i]-sum);
	}
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++)
	{
		if(m==0)break;
		while(b[i]>0)
		{
			b[i]--;
			m--;
		}
		if(b[i]==0)ans++;
	}
	cout<<ans;
	return 0;
}
