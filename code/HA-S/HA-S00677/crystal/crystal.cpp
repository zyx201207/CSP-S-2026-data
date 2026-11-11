#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+10;
int n;
long long m,a[MAXN],ans;

bool make(long long &a,long long b)
{
	long long c=abs(a-b);
	if (m<c) return false;
	a+=c;
	m-=c;
	ans++;
	return true;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for (int i=1;i<n;i++)
	{
		if (!make(a[i],a[i+1])) break;
	}
	cout<<(ans+1);
	return 0;
}
