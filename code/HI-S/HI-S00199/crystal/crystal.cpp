#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int a[N],d[N];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	int n,m;
	cin>>n>>m;
	if(n==1){
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		d[i] = a[i]-a[i-1];
	}
	for(int i=2;i<=n;i++){
		d[i] += d[i-1];
	}
	int sum=0,maxx=0;
	for(int l=1,r=1;l<n;l++){
		if(r<l) r=l;
		int len = r-l+1;
		while(sum+len*(d[r+1]-d[r])<=m && r+1<=n && l<r+1){
			r++;
			sum += len*(d[r]-d[r-1]);
			len = r-l+1;
		}
		maxx = max(maxx,len);
		sum = sum-(d[r]-d[l]);
	}
	cout<<maxx;
	
	return 0;
}
