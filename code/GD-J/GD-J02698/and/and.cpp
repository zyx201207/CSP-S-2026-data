#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long a[N];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;++i) cin>>a[i];
	sort(a,a+n);
	int ans=a[n-1];
	for(int i=n-1;i>=n-m;--i)
	{
		ans=ans&a[i];
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
