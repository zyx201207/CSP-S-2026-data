#include<bits/stdc++.h>
using namespace std;

int n,num,ans = -1;
long long m,a[500009],x;

int main () {
	freopen("crystal .in","r",stdin);
	freopen("crystal .out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 1;i <= n;i++){
		for(int j = i+1;j <= n;j++){
			num++;
			if(x+(a[j]-a[j-1])*num>m){
				break;
			}
			x+=(a[j]-a[i])*num;
		}
		x = 0;
		ans = max(ans,num);
		num = 1;
	}
	cout << ans;
	return 0;
}
