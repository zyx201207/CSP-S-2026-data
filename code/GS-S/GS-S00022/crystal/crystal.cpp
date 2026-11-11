#include <bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500005];
int main  ()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long b;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	b=a[2]-a[1];
	m-=(m%b);
	m/=b;
	cout <<m;
	return 0;
}
