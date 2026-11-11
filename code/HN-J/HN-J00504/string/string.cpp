#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N = 2e5+5;
struct node
{
	int x;
	char y;
}a[N];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n; 
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i].x>>a[i].y;
	}
	int l=1,r=n;
	int ldq=0,rdq=0;
	int cnt=0;
	while(l<=r)
	{
		if(a[l].y!=a[r].y) cnt++;
		ldq++,rdq++;
		if(ldq==a[l].x) l++;
		if(rdq==a[r].x) r--;
	} 
	cout<<cnt;
	return 0;
}

