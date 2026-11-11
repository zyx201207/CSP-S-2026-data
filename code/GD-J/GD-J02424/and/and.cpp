#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	int n,m,a[200010],ans;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	while(m==0)
	{
		ans=a[n]&a[n-1];
		n--;
		m--;
	}
	cout<<ans;
	return 0;
}
