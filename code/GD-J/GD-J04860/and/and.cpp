#include<bits/stdc++.h>
using namespace std;
long long n,m,t,a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,[](long long A,long long B){
		return A>B;
	});
	t=a[1];
	for(int i=1;i<=m;i++)
	{
		t=t&a[i];
	}
	cout<<t;
	return 0;
}
