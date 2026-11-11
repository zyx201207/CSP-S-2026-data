#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll minn(ll x,ll y)
{
	if(x < y) return x;
	return y;
}
const int N = 2e5 + 10;
int n;
int a[N];char c[N];
ll l,r,lsum,rsum,lst,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i = 1; i <= n; i++)
	{
		cin>>a[i]>>c[i];
	}
	ans = 0;
	lst = -1;
	l = 1;
	r = n;
	lsum = a[1];
	rsum = a[n];
	while(l <= n && r >= 1)
	{
//		printf("%lld %lld %lld %lld %lld %lld\n",
//		l,r,lsum,rsum,lst,ans);
		if(c[l] != c[r])
		{
			ans += (minn(lsum,rsum) - lst);
		}
		lst = minn(lsum,rsum);
		if(lsum == rsum)
		{
			if(l == n && r == 1) break;
			l++;
			r--;
			lsum += a[l];
			rsum += a[r];
		}
		else if(lsum > rsum)
		{
			r--;
			rsum += a[r];
		}
		else
		{
			l++;
			lsum += a[l];
		}
	}
	cout<<ans / 2<<endl;
	return 0;
}

