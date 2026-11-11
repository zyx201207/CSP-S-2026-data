#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int a[200005];
    long long ans = 0;
    string b;
    string c;
    string d;
    bool t = 1;
    int n;
    cin >> n;
    for(int i = 1;i<=n;i++) {
    	cin >> a[i];
    	cin >> c;
    	if(t==1 && b==c) {
    		ans+=a[i];
		}
		else{
			t = 0;
			ans = 0;
			for(int j = 1;j<i;j++) {
				ans+=a[j];
			}
		}
    	b = c;
    	d = d+c;
	}
	bool s = 1;
	for(int i = 0;i<=n;i++) {
		if(d[i] != d[i-1]) {
			s = 0;
		}
	}
	
	
	if(s == 1) {
		cout << 0;
	}
	else {
		cout << ans;
	}
	
    return 0;
}
