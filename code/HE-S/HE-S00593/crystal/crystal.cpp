#include<bits/stdc++.h>
using namespace std;
long long n,m,a[5000001],cnt=0,k=0,ans=0;
bool b1=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if(i==2)
		{
			k=a[i]-a[i-1];
		}
		if(i>2)
		{
			if(a[i]-a[i-1]!=k) b1=0;
		}
	}
	if(b1==1)
	{
		cnt=1+floor((sqrt(8*m*k+k*k*1.0)-k)/(2*k));
		if(cnt<=n) cout<<cnt;
		else cout<<n;
	}
	else
	{
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)
		{
			long long v=m,x=0;
			while(a[i]==a[i+1]) i++;
			for(int j=i;j>=1;j--)
			{
				if(v==0) break;
				if(a[i]-a[j]<=v)
				{
					v-=a[i]-a[j];
					x++;
				}
			}
			ans=max(ans,x);
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
