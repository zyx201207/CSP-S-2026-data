#include<bits/stdc++.h>
using namespace std;
const int N=1000010;
long long n,m,num,k,maxx;
long long a[N],s[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	k=m;
	for(int i=2;i<=n;i++)
	{
		for(int j=i;j>=1&&k;j--)
		{
			if(k-(a[i]-a[j])>=0)
			{
				num+=1;
				k-=a[i]-a[j];
			}
		}
		maxx=max(maxx,num);
		num=0;
		k=m;
	}
	cout<<maxx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
