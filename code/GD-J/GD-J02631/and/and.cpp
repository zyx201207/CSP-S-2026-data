#include<bits/stdc++.h>
using namespace std;
const int N = 2*1e5+5;

int n, m, a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	if(m == 1){
		int ans = -1;
		for(int i=1;i<=n;i++) ans = max(ans, a[i]);
		cout << ans; 
	}else if(m == 2){
		int ans = -1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(i != j) ans = max(ans, a[i] & a[j]);
		cout << ans;
	}else if(m == n-1){
		int ans = -1;
		for(int i=1;i<=n;i++){
			int cnt;
			if(i != 1) cnt = a[1];
			else cnt = a[2];
			for(int j=1;j<=n;j++)
				if(i != j)
				cnt &= a[j];
			ans = max(ans, cnt);
		}
		cout << ans;
	}else{
		int ans = a[1];
		for(int i=2;i<=n;i++)
			ans &= a[i];
		cout << ans;
	}
}
