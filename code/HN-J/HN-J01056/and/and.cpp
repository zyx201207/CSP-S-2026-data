#include <bits/stdc++.h>
using namespace std;
long long a[100005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,k;
	cin >>n>>k;
	for(int i=0;i<n;i++) cin >>a[i];
	sort(a,a+n,greater<int>());
	cout <<a[0]&&a[1];
	return 0;
}
