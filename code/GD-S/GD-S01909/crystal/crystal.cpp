#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

const int N=5e5+10;

ll a[N];
int n;
ll m;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	ll t=m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	ll ans=0,x=0;
	for(int i=n;i>=1;i--){
		for(int j=1;j<i;j++){
			if(m>=(a[i]-a[j])){
				m-=(a[i]-a[j]);
				x++;
			}
		}
		x++;
		m=t;
		ans=max(ans,x);
		x=0;
	}
	cout << ans;
}
