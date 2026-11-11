#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N=2e5+5,M=5e3+5,mod=1e9+7,INF=1e18;
int n,m,k,a[N],da,b[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n==1)//只有一个，不需要花费 
	{
		cout<<1;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		b[++m]=a[i+1]-a[i];
	sort(b+1,b+m+1);
	if(b[1]==b[m])//全部相等
	{
		cout<<0;
		return 0;
	}
	bool bj=1;
	int w=b[2]-b[1];
	for(int i=3;i<=m;i++)
		if(b[i]-b[i-1]!=w) bj=0;
	if(bj)//特殊性质 
	{
		cout<<k/(w*(w+1)/2);
		//w不为0，若w为0，则全部相等，前面已经判断过了 
		return 0;
	}
	for(int l=1;l<=n;l++)
		for(int r=l;r<=n;r++)
		{
			int s=0;
			for(int i=l;i<r;i++)
				s=s+(i-l+1)*(a[i+1]-a[i]);
			if(s<=k) da=max(da,r-l+1);
		}
	cout<<da;
	return 0;
}
