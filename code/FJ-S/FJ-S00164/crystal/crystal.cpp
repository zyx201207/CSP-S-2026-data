#include <bits/stdc++.h>
using namespace std;
int a[500005],b[500005];
int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,cnt = 0,ans = 0;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	long long cha = a[2] - a[1];
	for(int i=1;i<=n;i++){
		cnt = 0;
		for(int j=1;j<=i-1;j++){
			cnt += j;
		}
		b[i] = cnt * cha;
	}
	for(int i=1;i<=n;i++){
		if(m >= b[i]){
			ans++;
		}
	}
	cout << ans;
	
	
	
	return 0;
}
