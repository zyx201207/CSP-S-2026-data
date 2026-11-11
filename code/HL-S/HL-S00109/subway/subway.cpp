#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
int w[N],a[N],t[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    for(int i = 0;i<m;i++){
    	cin >> w[i];
	}
	for(int i = 0;i<m;i++){
		ans += w[i];
	}
	for(int x = 0;x<n;x++){
		int k;
		cin >> k;
		for(int i = 0;i<k;i++){
			cin >> a[i] >> t[i];
		}
		int ans = 0;
		
		for(int j = 0;j<k;j++){
			ans+=j[i];
		}
		cout << ans;
	}
	
	return 0;
}
