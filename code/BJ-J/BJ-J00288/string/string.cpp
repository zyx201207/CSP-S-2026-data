#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=2e5+5;
ll n;
struct Node{
    char c;
    ll len;
}s[N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(ll i=1;i<=n;i++)
        cin >> s[i].len >> s[i].c;
    //good not manacher
    ll h=1,e=n;
    //h->n,e->1
    long long ans=0;
    long long nowl=s[h].len,nowr=s[e].len;
    while(h<e){
        long long k=min(nowl,nowr);
        if(s[h].c!=s[e].c)ans+=k;
        if(k==nowl){
            h++;
            nowr-=nowl;
            nowl=s[h].len;
        }
        else {
            e--;
            nowl-=nowr;
            nowr=s[e].len;
        }
    }
    cout << ans << "\n";
    return 0;
}
