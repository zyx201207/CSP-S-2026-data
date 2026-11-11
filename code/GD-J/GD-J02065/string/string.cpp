#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
long long sum,n,num,u=1,ans;
struct ox
{
	long long shu;
	string mu;
}a[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].shu>>a[i].mu;
		sum+=a[i].shu;
	}
	num=sum/2;
	long long f=n;
	while(1)
	{
		if(u>=f)
		{
			break;
		}
		if(a[u].mu==a[f].mu)
		{
			int mi=min(a[u].shu,a[f].shu);
		    a[u].shu-=mi;
		    a[f].shu-=mi;
		    if(a[u].shu==0) u++;
		    if(a[f].shu==0) f--;
		}
		else
		{
			int mi=min(a[u].shu,a[f].shu);
			ans+=mi;
		    a[u].shu-=mi;
		    a[f].shu-=mi;
		    if(a[u].shu==0) u++;
		    if(a[f].shu==0) f--;
		}
	}
	cout<<ans;
	return 0;
}
