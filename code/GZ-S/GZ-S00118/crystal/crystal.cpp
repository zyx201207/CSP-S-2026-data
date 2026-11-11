//GZ-S00118 德江县实验中学 刘龙成智
#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[50005],ans,minn,pos;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	while(m>0)
	{
		minn=a[1],pos=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]<=minn){
				minn=a[i];
				pos=i;
			}
		}
		a[pos]++;
		m--;
		minn=a[1],pos=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]<=minn){
				minn=a[i];
				pos=i;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(a[pos]==a[i])ans++;
		}
		b[ans]++;
	}
	for(int i=1;i<=n;i++)
	cout<<a[i]<<"　";
	for(int i=n;i>=1;i--)
	{
		if(b[i]!=0)
		{
			cout<<b[i];
			break;
		}
	}
	return 0;
}

