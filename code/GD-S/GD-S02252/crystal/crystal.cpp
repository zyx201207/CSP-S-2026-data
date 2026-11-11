#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e5+5;

int n;
unsigned long long m;
long long a[MAXN];

bool cmp(long long a,long long b){return a > b;}

bool check(int i)
{
	long long cnt = 0;
	int j;
	for(j = i+1;j <= n;j++)
	{
		if(a[i] - a[j] > m - cnt) return false;
		cnt += a[i] - a[j];
	}
	return true;
}

int deal()
{
	int l = 1,r = n;
	while(l <= r)
	{
		int mid = (l+r)/2;
		if(check(mid)) r = mid-1;
		else l = mid + 1;
	}
	return l;
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	sort(a+1,a+n+1,cmp);
	cout << n - deal() + 1;
	return 0;
 } 
