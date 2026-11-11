#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,a,ans;
char ch;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%lld",&n);
    while(n--){
        cin >> a >> ch;
        for(LL i = 1;i <= a;i++) s += ch;
    }
    LL len = s.size(),mid = len / 2;
    for(LL i = 0;i < mid;i++){
        if(s[i] != s[len - i - 1]){
            ans++;
        }
    }
    printf("%lld",ans);
    return 0;
}
