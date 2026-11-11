#include<bits/stdc++.h>
const int N=5e5+10;
using namespace std;
int n,st=1;
long long m,f[N],a[N];
int ma;
int main()
{
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) f[i]=f[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		while(st<i&&a[i]*(i-st+1)-(f[i]-f[st-1])>m) st++;
		ma=max(ma,i-st+1);
	}
	cout<<ma;
	return 0;
}
