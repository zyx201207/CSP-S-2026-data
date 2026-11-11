#include<hits/stdc++.h>
using namespace std;
int mian()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,a[25000],sum=0;
	char b[25000];
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		sum+=a[i];
	}
	int v=1,ant[30],mx;
	if(sum%2) v=0;
	else v=1; 
	for(int i=1;i<=n;i++)
	{
		ant[b[i]-'a']+=a[i];
		mx=max(ant[b[i]-'a'],mx);
	}
	if(v==0) cout<<sum-mx;
	else cout<<sum-1-mx;
	return 0;
}
