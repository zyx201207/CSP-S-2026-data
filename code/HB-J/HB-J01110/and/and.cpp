#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll n,m;
ull maxn;
ull a[200005],f[2005][2005];
bool b[200005];
ull any=1073741823;
ll y[200005];
ull pos;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],f[i][0]=a[i];
	//sort(a,a+n+1,cmp);
	//f[0]=a[1];
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n&&k!=j;k++){
				f[j][i]=max((f[j][i-1]&a[k]),f[j][i]);
			}
		}
	}
	//for(int i=1;i<=n;i++){
	//	for(int j=1;j<=m;j++){
	//		cout<<f[i][j]<<" ";
	//	}
	//	cout<<endl;
	//}
	for(int i=1;i<=n;i++){
		maxn=max(maxn,f[i][m]);
	}
	cout<<maxn;
	//cout<<f[n][m];
	return 0;
}
// f[x]=f[x-1]&a[i];
//zhuan huan fang cheng hao lie , dan chushihua?
// buxing o(n^2m)zao chao le
//qwq
