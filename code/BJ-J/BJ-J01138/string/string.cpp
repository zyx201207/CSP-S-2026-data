#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 3e5 + 5;
struct{
    ll l , r , len;
    char c;
}a[N];

ll n , sum = 0 , ans = 0;


int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    cin>> n;
    ll mo_wei = 1;
    for( int i = 1 ; i <= n ; i++ ){
        ll x;
        char z;
        cin>> x >> z;
        sum += x;
        a[i].c = z;
        a[i].len = x;
        a[i].l = mo_wei;
        mo_wei += x-1;
        a[i].r = mo_wei;
        mo_wei++;
    }
    ll l_id = 1 , r_id = n;
    ll cnt = 0;
    while( l_id < r_id ){
        cnt++;
        ll l_len = a[l_id].len , r_len = a[r_id].len;
        char l_c = a[l_id].c , r_c = a[r_id].c;
        if( l_len == r_len ){
            if( l_c != r_c )  ans += l_len;
            l_id++;
            r_id--;
        }
        else if( l_len < r_len ){
            if( l_c != r_c )  ans += l_len;
            l_id++;
            a[r_id].len -= l_len;
        }
        else{
            if( l_c != r_c )  ans += r_len;
            r_id--;
            a[l_id].len -= r_len;
        }
    }
    cout<< ans;

    return 0;
}
