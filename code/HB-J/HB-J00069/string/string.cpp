#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,b) for(int i = a;i <= b;i++)
using namespace std;
int n;
struct node{
    ll n;
    char c;
}ci[200005];
int main(){
    //Logos-super big cup!
    //XX XXXX!
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    rep(i,1,n){
        cin >> ci[i].n >> ci[i].c;
    }
    int l = 1,r = n;
    ll ans = 0;
    while(l < r){
        if(ci[l].n == ci[r].n){
            if(ci[l].c != ci[r].c) ans += ci[l].n;
            l++,r--;
        }else if(ci[l].n < ci[r].n){
            if(ci[l].c != ci[r].c) ans += ci[l].n;
            ci[r].n -= ci[l].n;
            l++;
        }else{
            if(ci[l].c != ci[r].c) ans += ci[r].n;
            ci[l].n -= ci[r].n;
            r--;
        }
    }
    cout << ans;
    return 0;
}
