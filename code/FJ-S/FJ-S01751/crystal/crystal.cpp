# include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n;
long long m,a[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	int l=1,Ans=1;
	long long Now=0;
	for(int r=1;r<=n;r++)
	{
		Now+=(a[r]-a[r-1])*(r-l);
		while(Now>m && l<=r)
			Now-=a[r]-a[l],++l;
		Ans=max(Ans,r-l+1);
	}
	cout<<Ans;
	return 0;
}