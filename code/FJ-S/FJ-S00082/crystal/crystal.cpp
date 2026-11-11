#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans=1;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long l=0,need=0,allneed=0;
	for(long long i=2;i<=n;i++)
	{
		need+=(a[i]-a[i-1])*(i-1-l);//这里忘记写-l卡了半小时 
		allneed+=(a[i]-a[i-1])*(i-1);
		while(need>m)
		{
			l++;
			need-=a[i]-a[l];
		}
		ans=max(i-l,ans);
//	if(i-l>314000)cout<<i<<" "<<l<<" "<<need<<" "<<allneed<<" "<<i-l<<"\n";
	}
	cout<<ans;
	return 0;
}
//Oct31==Dec25?

//finish at 15:17
