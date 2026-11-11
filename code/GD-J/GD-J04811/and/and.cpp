#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2000005;
ll m,n,a[N],ans=1;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n,greater<int>());
	for(int i=1;i<m;i++)
	{
		if(!(a[i]&a[i-1]))
		{
			continue;
		}
		a[i]=a[i]&a[i-1];
	}
	cout<<a[m-1];
	return 0;
}
