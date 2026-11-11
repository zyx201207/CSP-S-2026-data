#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[10000005];
int main()
{
	freopen("crysta.in","r",stdin);
	freopen("crysta.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	long long ans=0;
	long long cnt=m;//cnt统计操作次数 
	bool flag=false;
	sort(a+1,a+n+1);
	for(int i=3;i<=n+1;i++)
	{
		for(int j=2;j<i;j++)
		{
			if(a[j]==a[j-1]) continue;
			cnt-=(a[j]-a[j-1]);
			if(cnt<0)   {flag=true; break;}
			a[j-1]=a[j];
		}
		if(flag) break;
		ans=i-1;
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
