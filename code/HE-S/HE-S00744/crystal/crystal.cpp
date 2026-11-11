#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005],sum[500005];
long long top[500005],tep[500005];
long long sun[500005],tmp;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i = 1;i<=n;i++)
	{
		cin>>a[i];
		sum[a[i]]++;
//		cout<<sum[a[i]]<<endl;
	}
	sort(a+1,a+n+1);
//	for(int i = 1;i<=n;i++)
//	{
//		cout<<a[i]<<' ';
//	}
//	判断如果都变成a[i]需要多少水晶，最后又有多少水晶
	for(long long i = 2;i<=n;i++)
	{
		tep[i]+=sum[a[i]];
		long long teep = 0;
		for(long long j = 1;j<=n;j++)
		{
			if(a[i]-a[j]>=0)
			{
				top[i]+=a[i]-a[j];
//				cout<<"第"<<j<<"次top"<<'['<<i<<']'<<"变为"<<top[i]<<endl;
				if(a[i]-a[j]!=0)
				{
					tep[i]++;
				}
//				cout<<"tep["<<i<<"]变为"<<tep[i]<<endl; 
			}
			if(top[i]<=m&&teep==i-1)
			{
				sun[tmp] = tep[i];
//				cout<<tep[i]<<"进入了最后的比大小"<<endl;
//				cout<<"sun["<<tmp<<"]"<<"变为"<<sun[tmp]<<endl;
				tmp++;
				break;
			}
			teep++;
		}
	 }
	sort(a+1,a+tmp);
	cout<<sun[tmp-1]; 
	return 0;
}
