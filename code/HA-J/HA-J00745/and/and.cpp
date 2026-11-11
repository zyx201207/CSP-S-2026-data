#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans;
struct T
{
	long long shi;
	int er;
}a[200005];
int help(long long x)
{
	int num=0;
	while(x>0)
	{
		if(x%2==1)
	    {
		    num++;
	    }
	    x/=2;
    }
	return num;
}
bool cmp(T y,T z)
{
	if(y.er==z.er)
	{
		return y.shi>z.shi;
	}
	return y.er>z.er;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].shi;
		a[i].er=help(a[i].shi);
	}
	sort(a+1,a+n+1,cmp);
	ans=a[1].shi;
	for(int i=2;i<=m;i++)
	{
		ans=a[i].shi&ans;
	}
	cout<<ans;
	return 0;
}
