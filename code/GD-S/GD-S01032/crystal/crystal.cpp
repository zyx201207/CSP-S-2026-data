#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+10;
ll a[N],c[N],b[N];
int n,m,ans=1;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	c[1]=0;
	for(int i=2;i<=n;i++){
		c[i]=c[i-1]+(a[i]-a[i-1]);
	}
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+c[i]*i;
	}
	if(n<=5000){
		for(int i=1;i<=n;i++){
			ll x=0;
			int y=0;
			for(int j=i;j>=1;j--){
				x+=a[i]-a[j];
				if(x<=m) y++;
				else break;
			}
			ans=max(ans,y);
		}
	}
	else{
		for(int i=1;i<=n;i++){
			if(b[i]<=m){
				ans=i;
			}
			else break;
		}
	}
	cout << ans;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	return 0;
} 
