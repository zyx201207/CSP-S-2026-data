#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+50;
int n,m,a[N],h[N],ans=0;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		h[i]=h[i-1]+a[i];
	int p=1,s=0;
	for(int i=1;i<=n;i++){
//		cout<<(i-p+1)*a[i]-(h[i]-h[p-1])<<"\n";
		while(p<i&&(i-p+1)*a[i]-(h[i]-h[p-1])>m)
			p++;
//		cout<<a[i]<<' ';
//		if(i-p+1>ans)
//			cout<<i<<' '<<p<<' '<<(i-p+1)*a[i]-(h[i]-h[p-1])<<"\n";
		ans=max(i-p+1,ans);
	}
	cout<<ans;
	return 0;
}
/*
8 1
0 1 2 2 2 2 2 10
*/
