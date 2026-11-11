#include<bits/stdc++.h>
using namespace std;
const long long MAXN=500010;
long long n,m,a[MAXN];
bool cmp(int x,int y)
{
	return x<y;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long i,temp=m,ans1=0,ans=-MAXN,j;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n,cmp);
	a[0]=1002147483647;
	a[n+1]=1002147483647;
	for(i=1;i<=n;i++)
	{
		if(a[i]==a[i+1])
			continue;
		ans1=0;
		temp=m;
		j=i;
		while(j>0)
		{
			if(a[i]-a[j]>temp)
				break;
			temp-=a[i]-a[j];
			ans1++;
			j--;
		}
		if(ans1>ans)
			ans=ans1;
	}
	cout<<ans<<endl;
	return 0;
}
