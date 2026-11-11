#include<bits/stdc++.h>
using namespace std;
long long n,m,i=1,maxn=1,q,cnt;
int a[500001];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	while(i!=n)
	{
		cin>>a[i];
		i++;
	}
	sort(a+1,a+n+1);
	while(i!=0)
	{
		q=m;
		cnt=1;
		for(int j=i-1;j>=1;j--)
		{
			q=q-a[i]+a[j];
			if(q<=0)
			{
				break;
			}
			cnt++;
		}
		maxn=max(maxn,cnt);
		i--;
	}
	cout<<maxn<<"\n";
	return 0;
}
