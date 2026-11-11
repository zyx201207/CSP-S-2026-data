#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=0,a[1000];
long long and1(long long x,long long y)
{
	long long i=0,sum=0;
	while((x>>i)!=0&&(y>>i)!=0)
	{
		if(((x>>i)&1)&&((y>>i)&1)) sum=sum+(1<<i);
		i++;
	}
	return sum;
}
void search(long long x,long long sum)
{
	if(x>=m)
	{
		ans=max(ans,sum);
	}
	else
	{
		for(int i=x+1;i<=n;i++)
		{
			search(i,and1(sum,a[i]));
		}
	}
	return;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) search(1,a[i]);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
