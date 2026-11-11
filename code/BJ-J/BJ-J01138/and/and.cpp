#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 3e5 + 5;
ll n , m , ans;
int er[N][100];
int top[N];
bool v[N] = {0};

void zhuan( ll x , ll i ){
    int cnt = 1;
    while(x){
        er[i][cnt] = x % 2;
        x /= 2;
        cnt++;
    }
    top[i] = cnt-1;
    return;
}

ll zhuan( int x ){
    ll sum = 1;
    while(x){
        sum *= 2;
        x--;
    }
    return sum;
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin>> n >> m;
    for( int i = 1 ; i <= n ; i++ ){
        ll x;
        cin>> x;
        zhuan(x,i);
    }
    int max_top = 0;
    for( int i = 1 ; i <= n ; i++ ){
        max_top = max( max_top , top[i] );
    }
    for( int i = max_top ; i >= 1 ; i-- ){
        int sum = 0;
        for( int j = 1 ; j <= n ; j++ ){
            if( v[j] == 0 && er[j][i] == 1 )  sum++;
        }
        if( sum >= m ){
            ans += zhuan(i-1);
            for( int j = 1 ; j <= n ; j++ ){
                if( er[j][i] == 0 )  v[j] = 1;
            }
        }
    }
    cout<< ans;

    return 0;
}
