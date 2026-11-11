#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
const int MAXN = 600000;

ll n,m;
int a[MAXN];
int aqz[MAXN];

int ans=1;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	
	sort(a+1,a+n+1);
	
	aqz[0] = a[0];
	for(int i=1;i<n;i++){
		aqz[i+1] = a[i+1] - a[i];
	}
	
	
	
	ll tmp = 0;
	int li = 1;
	
	for(int i=1;i<=n;i++) {
		tmp += aqz[i]*(i-li);
		
		while(tmp > m){
			tmp -= (a[i] - a[li]);
			li++;
		}
		ans = max(ans,(i-li+1));
	}
	cout << ans;
	return 0;
}
