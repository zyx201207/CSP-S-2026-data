#include<bits/stdc++.h>
using namespace std;

int main()
{
   freopen("and.in","r",stdin);
   freopen("and.out","w",stdout);
	long long n,m;
	long long a[200005]={},maxn=-1,a1[200005]={};
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		a1[i]=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			for(int k=0;k<m-1;k++){
				a1[i]=(a1[i]&a[j+k]);
			}
		}
	}
	for(int i=1;i<=n;i++) maxn=max(a1[i],maxn);
	cout<<maxn;
   return 0;
}
