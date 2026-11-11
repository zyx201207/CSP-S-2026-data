#include<bits/stdc++.h>
using namespace std;
#define mmm long long 
mmm n,m,a[500005];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	int x = a[2] - a[1],ans = 0;
	for(int i = 1;i <= n;i++){
		int y = i*(i+1)/2 * x;
		if(y <= m){
			ans = i+1;
		}
		else break;
	}
	cout << ans;
	return 0;
}
