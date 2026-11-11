#include <bits/stdc++.h>
using namespace std;
const int N=5e5;
int n,m,a[N],cnt=0,num,numla,ii,ma=0,sum=0,sumla=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j>=1;j--)
		{
			if(sum+a[i]-a[j]<=m)
			{
				sum+=a[i]-a[j];
				cnt++;
			}
			//cout<<"a[j]:"<<a[j]<<" "<<cnt<<" "<<sum+a[i]+a[j];
		}
		//cout<<endl<<"sum:"<<sum<<endl;
		ma=max(ma,cnt);
		sum=0;
		cnt=0;
	}
	cout<<ma;
	return 0;
}
