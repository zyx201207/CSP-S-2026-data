#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5+10;
int n,m,ans;
int a[N],diff[N];
bool flat = false;

void sort_merge(int l,int r)
{
	if(l == r) return ;
	int mid = (l+r)/2;
	sort_merge(l,mid);
	sort_merge(mid+1,r);
	vector<int> G;
	int ll = l,rr = mid+1;
	for(int i=l;i<=r;i++)
	{
		if(ll > mid) G.push_back(a[rr++]);
		else if(rr > r) G.push_back(a[ll++]);
		else if(a[ll] < a[rr])
		{
			G.push_back(a[ll++]);
		}
		else
		{
			G.push_back(a[rr++]);
		}
	}
	for(int i=0;i<G.size();i++)
	{
		a[l+i] = G[i];
	}
	
	return ;
}

void cheak()
{
	for(int i=2; i<n; i++)
	{
		if(diff[i] != diff[i+1]) return ;
	}
	int i=1,sum = 0;;
	while(sum<=m)
	{
		sum+=diff[2]*i;
		i++;
	}
	cout<<i-1;
	flat = true;
	return ;
}

signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];
		diff[i] = a[i] - a[i-1];
	}
	sort_merge(1,n);
	
	cheak();
	if(flat) return 0;
	
//	for(int i=1; i<=n; i++)
//	{
//		cout<<a[i]<<' ';
//	}
	
	int sum = 0, cnt = 0;;
	int l=1,r=1;
	while(r<=n)
	{
		r++;
		sum+=diff[r]*(r-l);
		cnt += diff[r];
		while(sum > m)
		{
			sum -= cnt;
			cnt -= diff[l+1];
			l++;
		}
		ans = max(ans,r-l);
//		cout<<sum<<' '<<cnt<<' '<<r-l<<'\n';
	}
	cout<<ans+1;
	
	return 0;
}
/*
5 8
-3 -1 2 2 7

*/
