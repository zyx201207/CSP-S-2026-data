#include<bits/stdc++.h>
using namespace std;
string s,s2;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,a,l=0;
    char c;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a >> c;
        l += a;
        while(a--){
            s += c;
        }
    }
    s2 = s;
    reverse(s.begin(),s.end());
    if(s2 == s){
        cout << 0;
        return 0;
    }
    long long ans = 0;
    for(long long i=0;i<l/2;i++){
        if(s[i]!=s2[i]){
            ans++;
            s[i] = s2[i];
        }
    }
    s2 = s;
    reverse(s.begin(),s.end());
    if(s2 == s){
        cout << ans;
        return 0;
    }
    if(l % 2 == 1){
        for(long long i=l/2+1;i<l;i++){
            if(s[i]!=s2[i]){
                ans++;
                s[i] = s2[i];
            }
        }
    }else{
        for(long long i=l/2+1;i<l;i++){
            if(s[i]!=s2[i]){
                ans++;
                s[i] = s2[i];
            }
        }
    }
    cout << ans;
    return 0;
}
