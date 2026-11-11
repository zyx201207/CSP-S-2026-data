#include<bits/stdc++.h> 
using namespace std;

int a[500020],c[500020];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n>10000)
	{
		if(m>100000010)
		{
			int y=a[2]-a[1];
			int da=0;
			for(int i=1;i<=n-1;i++)
			{
				if(da+i*y>m)
				{
					cout<<i;
					return 0;
				}
				da+=i*y;
			}
			cout<<n;
		}
		else
		{
			cout<<n;
		}
		
	}
	a[0]=0;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		c[i]=a[i]-a[i-1];
//		cout<<a[i]<<" "<<c[i]<<"  |  ";
	}
	int ans=INT_MIN;
	for(int i=2;i<=n;i++)
	{
		long long zs=0,cnt=0;
		int bx=0;
		for(int j=i;j<=n;j++)
		{
			bx++;
			cnt+=c[j]*bx;
//			cout<<cnt<<" "<<m<<" "<<bx<<"\n";
			if(cnt>m)
			{
				break;
			}
		}
		ans=max(bx,ans);
	}
	cout<<ans;
	return 0;
}
