#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll ans;
struct para{
    ll ci;
    char a;
}p[200005];
int st,en;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> p[i].ci >> p[i].a;
    }
    st = 0,en = n-1;
    while(st <= en){
        if(p[st].a != p[en].a){
            ans += min(p[st].ci,p[en].ci);
        }
        if(p[st].ci > p[en].ci){
                p[st].ci -= p[en].ci;
                en--;
            }else if(p[st].ci < p[en].ci){
                p[en].ci -= p[st].ci;
                st++;
            }else{
                en--;
                st++;
            }
    }
    cout << ans;
    return 0;
}
