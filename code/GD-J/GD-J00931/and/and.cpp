/* and.cpp */
#include<iostream>
using namespace std;

const int N=2e5+10;
int n,m,ans,a[N],v[N];
void pick(int x,int sum)
{
	if(x>m)
	{
		if(sum>ans)
			ans=sum;
		return;
	}
	for(int i=1;i<=n;++i)
	{
		if(v[i])
			continue;
		v[i]=1;
		if(x==1)
			pick(x+1,a[i]);
		else
			pick(x+1,sum&a[i]);
		v[i]=0;
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	pick(1,a[1]);
	cout<<ans;

	fclose(stdin);
	fclose(stdout);	
	return 0;
}
