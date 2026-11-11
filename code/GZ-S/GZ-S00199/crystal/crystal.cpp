//GZ-S00199 盘州市第二中学 敖孝桐 

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=500005;
ll a[MAXN];
int main(){
	freopen("crystal.in.in","r",stdin);
	freopen("crystal.out.out","w",stdout);
	ll m,n;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	ll ans=1;
	for(int i=2;i<=n&&m>0;i++){
		ll v=a[i]-a[i-1];
		v*=(i-1);
		if(m-v<0)break;
		else if(m-v>=0){
			ans++;
			m-=v;
			a[i-1]=a[i];
		}
	}
	cout<<ans;
	return 0;
}
