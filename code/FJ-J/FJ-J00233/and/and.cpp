#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N=2e5+5;
int n,m;
ll a[N],b[N];
int c[35];

bool cmp(ll a,ll b){
	return a>b;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i]; 
	
	for(int i=1;i<=n;i++){
		ll x=a[i];
		for(int j=30;j>=0;j--){
			if((x>>j)&1){
				c[j]++;
			}
		}
	}
	
	for(int j=30;j>=0;j--){
		if(!c[j]) continue;
		if(c[j]<m){
			for(int i=1;i<=n;i++){
				if((a[i]>>j)&1){
					a[i]^=(1ll<<j);
				}
			}
		}
	}
	
	sort(a+1,a+n+1,cmp);
	
	ll res=a[1];
	for(int i=2;i<=m;i++) res&=a[i];
	
	cout << res << "\n";
	return 0;
}
