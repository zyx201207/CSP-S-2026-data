#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],b[500005],maxx=-1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1),b[1]=0;
	for(int i=2;i<=n;i++)b[i]=b[i-1]+a[i]-a[i-1];
	for(int i=1;i<=n;i++){
		int l=0,r=i,mid;
		while(l+1<r){
			mid=(l+r)/2;
			if(b[i]-b[mid]>m)l=mid;
			else r=mid;
		}
		maxx=max(maxx,i-r+1);
	}
	cout<<maxx;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

5 1
4 4 4 4 4
*/
