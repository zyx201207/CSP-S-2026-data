#include<bits/stdc++.h>
using namespace std;

int n,m,a[200005];
int bb(int i)
{
	int ans=0;
	while(1<2)
	{
		if(i<2) break;
		i=i/2;
		ans++;
	}
	return ans;
}
int pp(int i)
{
	int ans=1;
	for(int k=1;k<=i;k++)	ans=ans*2;
	return ans;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);	
	cin>>n>>m;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==i-1) ans++;
	}
	sort(a+1,a+n+1);
	int w=bb(a[n])+1,k;
	for(int i=m;i>=1;i--)
	{
		int u=lower_bound(a,a+n,pp(w)-1)-a;
		k=a[u];
		w--;
	}
	cout<<k;
	return 0;
}
