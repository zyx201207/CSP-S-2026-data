#include <bits/stdc++.h>
using namespace std;
const int maxN = 2e5 + 5;
int n,m;
int a[maxN];
bool cmp(int x, int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	if(m==1){
		int mx = -1;
		for(int i=1;i<=n;i++){
			cin >> a[i];
			mx = max(mx, a[i]);
		} 
		cout << mx << "\n";
		return 0;
	}
	if(m==2){
		int mx = -1;
		for(int i=1;i<=n;i++){
			cin >> a[i];
		} 
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					mx = max(mx, a[i]&a[j]);
				}
			}
		}
		cout << mx << "\n";
		return 0;
	}
	if(m==n){
		cin >> a[1];
		int ans = a[1];
		for(int i=2;i<=n;i++){
			cin >> a[i];
			ans &= a[i];
		} 
		cout << ans << "\n";
		return 0;
	}
	if(m==n-1){
		for(int i=1;i<=n;i++){
			cin >> a[i];
		} 
		int mx = a[2];
		for(int i=3;i<=n;i++)
			mx &= a[i];
		for(int i=2;i<=n;i++){
			int cur = a[1];
			for(int j=1;j<=n;j++){
				if(i!=j) cur&=a[j];
			}
			mx = max(mx,cur);
		}
		cout << mx << "\n";
	}
	for(int i=1;i<=n;i++){
		cin >> a[i];
	} 
	long long mod = pow(2,30)-1;
	bool f = 1;
	for(int i=1;i<=n&&f;i++){
		if(a[i]&mod != a[i])
		  	f = 0;
	}
	if(f){
		sort(a+1,a+n+1,cmp);
		cout << a[2] << "\n";
		return 0;
	}
	for(int k=1;k<=18;k++){
		if(pow(2,k)==n){
			cout << a[n]-2 << "\n";
			return 0;
		}
	}
	
	return 0;
}
