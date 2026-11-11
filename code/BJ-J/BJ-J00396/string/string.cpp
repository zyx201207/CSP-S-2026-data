#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6+5;
int n,ans,a,b;
struct para{
    int lenth;
    char kind;
}str[N];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> str[i].lenth >> str[i].kind;
    }
    a = 1,b = n;
    while(b > a){
        if(str[a].lenth >= str[b].lenth){
            str[a].lenth -= str[b].lenth;
            if(str[a].kind != str[b].kind) ans += str[b].lenth;
            b--;
        }
        else{
            str[b].lenth -= str[a].lenth;
            if(str[a].kind != str[b].kind) ans += str[a].lenth;
            a++;
        }
        if(str[a].lenth == 0) a++;
        if(str[b].lenth == 0) b--;
    }
    cout << ans;
}