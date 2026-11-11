#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N=3e5+5,M=5e3+5,mod=1e9+7,INF=1e18;
int n,m,a[N],da;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1,greater<int>());
	for(int l=1,r=m;r<=n;l++,r++)
	{
		int s=-1;
		for(int j=l;j<=r;j++)
		{
			if(s==-1) s=a[j];
			else s=s&a[j];
		}
		da=max(da,s);
	}
	cout<<da;
	return 0;
}
