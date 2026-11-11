#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    string a;
    long long n,k = 0,ans = 0;
    cin >> n;
    for (int i = 1;i <= n;i++){
        long long m;
        char b;
        cin >> m >> b;
        for (long long j = 1;j <= m;j++){
            a[k++] = b;
        }
    }
    for (long long i = 0;i <= (k+1)/2-1;i++){
    	if (a[i] != a[k-i-1]) ans++;
	}
	cout << ans;
    return 0;
}
