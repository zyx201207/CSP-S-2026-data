#include<iostream>
#include<algorithm>
#define ll long long 
using namespace std;

const int N=500010;
int n;
ll m;
ll a[N], c[N];

int main(){
	
	ios::sync_with_stdio(0), cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	for(int i=1; i<=n; i++){
		c[i]=c[i-1]+a[i];
	}
	int ans=0;
	for(int i=1; i<=n; i++){
		int l=1, r=i;
		while(l<=r){
			int mid=(l+r)>>1;
			if(a[i]*mid-(c[i]-c[i-mid])<=m){
				l=mid+1;
			}else{
				r=mid-1;
			}
		}
		ans=max(ans, r);
	}
	cout << ans;
	
	return 0;
}
