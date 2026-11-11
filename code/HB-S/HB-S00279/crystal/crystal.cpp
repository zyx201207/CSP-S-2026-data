#include<bits/stdc++.h>
using namespace std;
int n,m,k,maxn;
int a[500005],b[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	while(m>0)
	{
		int i=1;
		while(a[i]==a[i+1]) i++;
		for(int j=1;j<=i;j++)
		{
			a[j]++;
			m--;
			if(m<=0) break;
		}
	}
	for(int i=1;i<=n;i++)
	{
		int cnt=1;
		while(a[i]==a[i+1]) cnt++,i++;
		maxn=max(maxn,cnt);
	}
	if(maxn!=1) cout<<maxn;
	else cout<<maxn;
	return 0;
}
