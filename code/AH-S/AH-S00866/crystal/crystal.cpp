#include<bits/stdc++.h>
using namespace std;
const int N=5e7+9,M=5e5;
long long n,a[N],m,ans,ansf1,b[N],ansf,c;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int j=1;j<=n;j++)
	{
		cin>>a[j];
	}
	sort(a+1,a+n+1);
	a[0]=a[1];
	for(int j=1;j<=n;j++)
	{
		b[j]=a[j]-a[j-1];
	}
	for(int j=1;j<=n;j++)
	{
		int l=j;
		ans=0;
		c=0;
		ansf1=1;
		while(l>=1 and ans<=m)
		{
			c+=b[l];
			ans+=c;
			l--;
			ansf1++;
		}	
		ansf=max(ansf,ansf1);
	}
	cout<<ansf-1;
	return 0;
}
