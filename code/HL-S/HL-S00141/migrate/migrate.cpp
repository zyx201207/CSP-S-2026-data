#include<bits/stdc++.h>
using namespace std;
int t,n,d,a[2000005],st,ans,minn=2147483647,sum;
void tow(int f,int w)
{
	if(f==w)
	{
		if(st<minn)
		{
			minn=st;
			sum=1;
		}
		else if(st==minn)sum++;
		return;
	}
	st++;
	if((a[f+2]-a[f])<=d&&f<w-1)
	{
		tow(f+2,w);
	}
	tow(f+1,w);
	st--;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t>>t;
	while(t--)
	{
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		} 
		for(int i=1;i<=n;i++)
		{
			for(int j=i+3;j<=n;j++)
			{
				minn=2147483647;
				sum=0;
				tow(i,j);
				if(sum==2)ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
