#include<bits/stdc++.h>
using namespace std;
long long len, a[200005], ans;
int n, l, r;
char s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i] >> s[i];
        len += a[i];
    }
    l = 1, r = n;
    while(l < r){
        long long m = min(a[l], a[r]);
        if(s[l] != s[r])ans += m;
        a[l] -= m, a[r] -= m;
        if(a[l] == 0)l++;
        if(a[r] == 0)r--;
    }
    cout << ans;
    return 0;
}
