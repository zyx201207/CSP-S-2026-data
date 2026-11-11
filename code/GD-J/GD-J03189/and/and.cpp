#include<bits/stdc++.h>
#define rep(i,n,m) for(int i(n);i<=(m);++i)
#define rev(i,n,m) for(int i(n);i>=(m);--i)
#define ll long long
using namespace std;
const int N=2e5+5;
int a[N],b[N];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	rep(i,1,n) cin>>a[i];
	rev(i,29,0){
		int k=0;
		rep(j,1,n){
			if(a[j]&(1<<i)) b[++k]=a[j];
		}
		if(k<m) continue;
		rep(j,1,k) a[j]=b[j];
		n=k;
	}
	int ans=(1<<30)-1;
	rep(i,1,m) ans&=a[i];
	cout<<ans<<"\n";
	return 0;
}
