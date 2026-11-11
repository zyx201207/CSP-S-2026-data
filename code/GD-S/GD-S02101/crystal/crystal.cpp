#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int N=2e6+10,mod=998244353;
typedef pair<int,int> pii;
typedef long long ll;
/*

*/
int C,T=1;
int n,m,a[N];
ll sum[N];
bool chk(int len){
	ll cnt=1e15;
	for(int l=1,r=len;r<=n;l++,r++)
		cnt=min(cnt,(ll)a[r]*len-sum[r]+sum[l-1]);
	return cnt<=m;
}
void mian(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int l=1,r=n,res=1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(chk(mid)) l=mid+1,res=mid;
		else r=mid-1;
	}
	cout<<res;
	return;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
//	cin>>C>>T;
	while(T--) mian();
	return 0;
}
