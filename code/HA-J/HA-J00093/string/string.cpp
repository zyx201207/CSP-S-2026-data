#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=200007;
int num[M];

signed main()
{
//	freopen("and.in","r",stdin);
//	freopen("and.out","r",stdout);
	int n,m,yu;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>num[i];
	sort(num+1,num+1+n);
	cout<<num[n];
	return 0;
}

