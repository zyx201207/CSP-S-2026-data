#include<bits/stdc++.h>
#define int long long
#define No ios::sync_with_stdio(0);
#define TLE cin.tie(0);
#define endl '\n'
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
const int N=5e5+10;
void _freopen(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
}
int a[N];
int b[N],c[N],d[N];
int n,m;
bool cheak(int x){
	int sum=0;
	for(int i=1;i<=x;i++){
		sum+=a[x]-a[i];
	}
	if(sum<=m) return 1;
	else return 0;
}
void solve2(){
	int l=1,r=n,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if(cheak(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<ans;
}
bool cmp(int len){
	for(int i=1;i<=n-len+1;i++){
		int r=i+len-1;
		//cout<<len<<" "<<i<<' '<<a[r]*len-(d[r]-d[i-1])<<endl;
		if(a[r]*len-(d[r]-d[i-1])<=m) return 1;
	}
	return 0; 
}
void solve3(){
	for(int i=2;i<=n;i++){
		b[i]=a[i]-a[i-1];
		c[i]=c[i-1]+b[i];
	//	cout<<b[i]<<" "<<c[i]<<endl;
	}
	int l=2,r=n,ans=1;
	while(l<=r){
		int mid=(l+r)/2;
		//cout<<l<<' '<<r<<" "<<mid<<" "<<cmp(mid)<<endl;
		//cout<<endl<<mid<<" ";
		if(cmp(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<ans;
}
void solve(){
	cin>>n>>m;
	bool p=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
	d[i]=d[i-1]+a[i];
		if(a[i]!=a[i-1]+1) p=1;		
	}

	if(p==0) solve2(); 
	else solve3();
}
signed main(){
	No TLE
	_freopen();
	int T=1;
	//cin>>T;
	while(T--){
		solve();
	}
}

