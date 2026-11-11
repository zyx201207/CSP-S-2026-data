#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+20;
ll n,m,i,j,a[N],d[N],ans,sum,l=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)
	{
		d[i]=d[i-1]+a[i];
	}
	for(i=1;i<=n;i++)
	{
		if(a[i]*(i-l+1)-(d[i]-d[l-1])<=m)
		{
			sum++;
		}
		else
		{
			ans=max(ans,sum);
			sum=0;
			l=i+1;
		}
	}
	cout<<max(sum,ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

7 5
-114514 2 3 4 5 6 12
*/
