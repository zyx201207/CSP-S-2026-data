#include<bits/stdc++.h>
using namespace std;
int n,num=0,x[200009];
long long ans=0;
char a[200009];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i]>>a[i];
		num+=x[i];
	}
	int i=1,j=n;
	for(int xxx=1;xxx<=200009;xxx++)
	{
		if(a[i]!=a[j])
		{
			ans+=min(x[i],x[j]);
			int f=x[i];x[i]-=min(x[i],x[j]);x[j]-=min(f,x[j]);
			if(x[i]<=0)i++;
			if(x[j]<=0)j--;
		}
		else
		{
			if(x[i]>=x[j])
			{
				x[i]-=x[j];x[j]=0;j--;
			}
			else
			{
				x[j]-=x[i];x[i]=0;i++;
			}
		}
		if(i==j)break;
	}
	cout<<ans<<endl;
	return 0;
}
