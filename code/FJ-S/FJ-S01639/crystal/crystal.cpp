#include<bits/stdc++.h>
#define lc (l+r)<<1
#define rc (l+r)<<1|1
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll n,m,a[N],b[N],res;
bool che(int l,int r){
//	cout<<l<<'>'<<r<<':'<<b[l]<<' '<<b[r]<<' '<<(r-l)*a[r]<<' '<<b[l]-b[r]-(r-l)*a[r]<<'\n';
	return b[l]-b[r]-(r-l)*a[r]<=m;//c
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++)
		a[i]=a[i+1]-a[i];
	for(int i=n-2;i>=1;i--)
		a[i]+=a[i+1];
	b[n-1]=a[n-1];
	for(int i=n-2;i>=1;i--)
		b[i]=a[i]+b[i+1];
//	for(int i=0;i<n;i++)
//		cout<<b[i]<<' ';
//	cout<<endl;
	for(int i=1;i<n-1;i++){
		int l=i,r=n,mi;ll ans=-1;
		while(l<r){
			mi=(l+r)>>1;
			if(che(i,mi)) ans=mi,l=mi+1;
			else r=mi;
		}
//		cout<<i<<':'<<ans<<'\n';
		res=max(res,ans-i+1);
	}
	cout<<res;
	return 0;
}
