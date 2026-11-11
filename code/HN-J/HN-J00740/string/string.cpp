#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
struct Node{
	long long x;
	char c;
};
Node a[N];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long sum = 0;
	int n,l,r;
	cin>>n;
	for(int i = 1 ; i <= n ; i++)cin>>a[i].x>>a[i].c;
	l = 1,r = n;
	while(l <= r)
	{
		if(a[l].c != a[r].c)sum += min(a[l].x,a[r].x);
		if(a[l].x == a[r].x)l++,r--;
		else if(a[l].x > a[r].x)a[l].x -= a[r].x,r--;
		else a[r].x -= a[l].x,l++;
	}
	cout<<sum;
	return 0;
}
