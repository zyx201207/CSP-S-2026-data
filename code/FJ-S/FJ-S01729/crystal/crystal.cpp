#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n;
long long m,s[N],a[N],num[N],ans;
bool cmp(int x,int y)
{
	return x<y;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for(int i=2;i<=n;i++)
	{
		s[i]=a[i]-a[i-1];
		num[i]=num[i-1]+s[i];
	//	cout<<i<<num[i]<<"\n";
	}
	long long cnt=0;
	long long sum=0;
	int j=1;
	int x=0;
	for(int i=1;i<=n;i++)
	{
		cnt+=s[i]*(i-1-x);
	//	cout<<i<<sum<<cnt<<"\n";
		if(cnt<=m)
		{
			sum++;
			ans=max(ans,sum);
		}
		else
		{
			while(cnt>m)
			{
				cnt-=a[i]-a[j];
			//	cnt-=num[i]-num[j];
			//	cout<<i<<cnt<<"\n";
				j++;
				x++;
				sum--;
			}
			sum++;
			ans=max(ans,sum);
		}
	}
	cout<<ans<<"\n";
	return 0;
} 
