#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    long long a[100005];
    char c[100005];
    cin >> n;
    string s = "", s1;
    for(int i=1; i<=n ;i++){
        cin >> a[i] >> c[i];
        for(int j=1; j<=a[i]; j++){
            s += c[i];
        }
    }
    long long ans = 0;
    long long q = 0, p = s.size()-1;
    while(q < (s.size()+1)/2){
        if(s[q] != s[p]){
            ans++;
        }
        q++;
        p--;
    }
    cout << ans;
    return 0;
}
