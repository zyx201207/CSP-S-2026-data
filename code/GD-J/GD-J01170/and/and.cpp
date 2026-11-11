#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
typedef long long ll;
const int MAXN=200005;
ll n,m,a[MAXN],ans[MAXN],s=0;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=m;i++)
	{
		if(a[i]==a[i-1])
		{
			continue;
		}
		s++;
		ans[s]=a[i];
	}
	cout<<ans[m];
	return 0;
}
