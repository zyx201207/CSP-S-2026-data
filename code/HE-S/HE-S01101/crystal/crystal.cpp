#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5+5;
ll a[N],b[N],f[N];
ll n,m,sum;
bool flag=1,isdeng=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum += a[i];
		if(a[i] != i)
			flag = 0;
	}
	for(int i=3;i<=n;i++)
		if(a[i] - a[i-1] != a[i-1]-a[i-2])
			isdeng = 0;
	
	ll cha = a[2]-a[1];
	
	sort(a+1,a+n+1);
	
	if(m == 0)
	{
		cout<<1;
		return 0;
	}
	
	if(flag)
	{
		int cnt=0,idx=2;
		for(int i=1;i<=m;i++)
		{
			cnt++;
			f[i] = idx;
			if(cnt == idx)
			{
				idx++;
				cnt=0;
			}
		}
		cout<<f[m];
		return 0;
	}
	
	if(isdeng)
	{
		int cnt=0,idx=1,cur=cha;
		for(int i=0;i<=m;i++)
		{
			cnt++;
			f[i] = idx;
			if(cnt == cur)
			{
				idx++;
				cur*=2;
				cnt=0;
			}
		}
		cout<<f[m];
		return 0;
	}
	
	ll l=1,r=n,ne=0;
	double mid;
	while(l!=r)
	{
		mid = double(double(sum)/double(r-l+1));
		ne=0;
		for(int i=l;i<=r;i++)
		{
			ne += a[r]-a[i];
		}
		if(ne <= m)
		{
			cout<<r-l+1;
			return 0;
		}
		if(abs(a[l] - mid) > abs(mid - a[r]))
		{
			sum -= a[l];
			l++;
		}
		else
		{
			sum -= a[r];
			r--;
		}
	}
	cout<<1;
	return 0;
}
