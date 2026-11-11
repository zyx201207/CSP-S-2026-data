#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+5;
const int inf=2e9;
const int mod=1e9+7;
ll n,m,ans;
ll a[N],c[N],pre[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i]; 
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		c[i]=a[i]-a[i-1];
		pre[i]=pre[i-1]+c[i];
	}
	ll l=1,sum=0;
//	for(int i=2;i<=n;i++){
//		cout << pre[i] << " ";
//	}cout << endl;
//	for(int i=2;i<=n;i++){
//		cout << c[i] << " ";
//	}cout << endl;
	for(int r=1;r<=n;r++){
		sum+=c[r]*(r-l);
		while(sum>m && l<r){
			sum-=(pre[r]-pre[l]);
			l++;
		}
		ll ls=r-l+1;
		ans=max(ans,ls);
//		cout << l << " " << r << " " << sum << endl;
	}
	cout << ans;
	return 0;
}

