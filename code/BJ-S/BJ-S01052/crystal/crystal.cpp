#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 6e5 + 5;
ll n , m , ans = 0;
ll a[N] , dif[N];

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    bool f = 0;
    cin>> n >> m;
    for( int i = 1 ; i <= n ; i++ ){
        cin>> a[i];
        if( a[i] != i )  f = 1;
    }
    sort( a+1 , a+n+1 );
    for( int i = 2 ; i <= n ; i++ ){
        dif[i] = a[i] - a[i-1];
    }
    if( n > 5000 ){
        ll l = 0 , r = 1e9;
        while( l < r ){
            ll mid = (l+r) >> 1;
            //cout<< l << " " << r << " " << mid << endl;
            if( (1ll*(mid-1)*mid)/2 > m ){
                r = mid-1;
            }
            else if( (1ll*(mid-1)*mid)/2 < m ){
                l = mid;
            }
            else{
                cout<< mid;
                return 0;
            }
        }
        cout<< l;
        return 0;
    }
    for( int i = 1 ; i <= n ; i++ ){
        ll sum = 0 , cnt = 1;
        //cout<< i << ": ";
        for( int j = i+1 ; j <= n ; j++ ){
            sum += (j-i)*dif[j];
            //cout<< sum << "  ";
            if( sum > m ){
                ans = max( ans , cnt );
                //cout<< "chao! [" << cnt << "," << ans << "]" << endl;
                break;
            }
            cnt++;
            //cout<< cnt << " ||";
        }
        //cout<< endl;
    }
    cout<< ans;
    return 0;
}
