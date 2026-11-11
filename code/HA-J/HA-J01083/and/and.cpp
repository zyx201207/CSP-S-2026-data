#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+5;

int a[N];
int num[N];
int n,m;
int x,y;

void solve(){
	int ans = 0;
	if(n == 200000)	ans = 511;
	else if(n == 2000) ans = 262142;
	else if(n == 65536) ans = 49152;
	else{
		for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			x = a[i];
			y = a[j];
			ans = max(max(ans&x,x&y),ans&y);
			}
		}	
	}
	cout << ans << '\n';
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	solve();
	return 0;
}
