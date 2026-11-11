#include <bits/stdc++.h>

#define ll int
#define maxn 2000007
#define N  3145141145141145140

using namespace std;

ll T , n , m , S  , ans , d[maxn] , q[maxn] , fa[maxn] , s[maxn] , tot , a[maxn] , b[maxn] , c[maxn] , sz[maxn] , q2[maxn] , st[maxn] , len , tt[maxn];
vector< int >v[maxn] , e[maxn];

ll U[maxn] , V[maxn] , vis[maxn] , p[maxn] , deg[maxn];

void dfs( int k )
{
    d[k] = d[fa[k]] + 1; q[k] = k; sz[k] = 1;
    for( int i = 0 ; i< v[k].size() ; ++i )
        if( v[k][i] != fa[k] ) {
            fa[v[k][i]] = k; dfs( v[k][i] );
            if( d[q[v[k][i]]] > d[q[k]] ) q[k] = q[v[k][i]];
            sz[k] += sz[v[k][i]];
        }
}

void co( int k , int C)
{
    c[k] = C;
     for( int i = 0 ; i< v[k].size() ; ++i )
        if( v[k][i] != fa[k] ) {
            co( v[k][i] , C );
        }
}

ll get( ll l , ll r , ll k )
{
    return max(min( r , k ) - l + 1 , 0 );
}

void work( ll k )
{
    for( int i = 1 ; i <= n; ++i ) a[i] = q2[i] = c[i] = 0;
    fa[s[1]] = 0; dfs( s[1] );
    for( int i = 1 ; i < tot ; ++i ) {
        c[s[i]] = 0; q2[i] = 0;
        for( int j =0 ; j < v[s[i]].size() ; ++j )
            if( v[s[i]][j] != s[i + 1] && v[s[i]][j] != s[i - 1] ) {
                co( v[s[i]][j] , i );
                q2[i] = max( q2[i] , d[q[v[s[i]][j]]] - d[s[i]] );
            }
    }
    for( int i = 1 ;i <= n ; ++i ) if( d[q[i]] - d[i] <= k ) a[c[i]] ++;
    for( int i = tot ; i>= 1 ; --i ) a[i] += a[i + 1];
  //  for( int i = 1 ;i<= tot ; ++i ) cout << q2[i] << " ";
   // cout <<"\n";
    ll sum= 0 , pp = 0; len = 0;
    for( int i = tot - 1 ; i>= 1 ; --i ) {
        if( tot - i + q2[i] >= pp ) {
            len = 2;
            ll tmp = tot - i + q2[i];
            st[1] = tot - ( tmp / 2 ); st[2] = i;
            sum = get( q2[i] , st[1] - 1 - i + q2[i] , k );
            pp = tot - i + q2[i];
        }else {
            while( len && q2[st[len]] < st[len] - i + q2[i] ) {
                sum -= get( q2[st[len]] , q2[st[len]] + st[len - 1] - st[len] - 1 , k); len --;
            }
            sum += get( q2[i] , q2[i] + st[len] - i - 1 , k ); st[++len] = i;
        }
       // cout << len <<"\n";
        a[i] += min( tot - st[1] , k ) + 1 + sum;
    }
   //for( int i = 1 ;i<= tot ; ++i ) cout << a[i] <<" " <<sz[i] <<"\n";;
   // cout << "\n";
    for( int i = 1 ;i<= n ; ++i ) tt[i] = 0;
    for( int i = 1 ; i <= tot ; ++i ) tt[s[i]] = max( sz[s[i]] - a[i] , 1 );
    for( int i = 1 ;i <= n ; ++i ) a[i] = tt[i];
}

ll check( ll k )
{
    work( k );
    //return 0;
    for( int i = 1 ; i <= n ; ++i ) b[i] = a[i];
    for( int i = 1 ; i * 2 <= tot ; ++i ) swap( s[i] , s[tot - i+ 1] );
    work( k );
    ll sum = n + 1;
    for( int i = tot ; i > 1 ; --i ) sum= min( sum , a[s[i]] + b[s[i - 1]] );
    return sum;
}


                queue< int >qu1 , qu2;

int main()
{
    freopen( "hub.in" , "r" , stdin );
    freopen( "hub.out" , "w" , stdout );
    ios::sync_with_stdio( false );
    cin.tie( 0 );
    cin >> T >> T;
    while( T -- ) {
        cin >>n >>m; ans = n + 1;
        for( int i = 1;  i < n ; ++i ) {
            ll s1, s2; cin >>s1 >>s2; U[i] = s1; V[i] = s2;
            v[s1].push_back( s2 ); v[s2].push_back( s1 );
        }
        dfs( 1 ); S = q[1];
        fa[S] = 0; dfs( S ); ll to = q[S]; tot = 0;
        while( to ) {
            s[++tot] = to; to = fa[to];
        }
        ll pos = s[(tot + 1) / 2];
        fa[pos] = 0; dfs( pos );
        for( int i = 1 ; i <= n ; ++i ) a[i] = d[q[i]] - d[i] + 1;
        sort( a + 1 , a + n + 1 );
        ans = a[n - m]; //cout << n <<" " <<m <<" " <<a[0] << "\n";
        //cout << check( 13 ); return 0;
        if( m >= 2 ) {
            if( 1) {
                ll l = 1 , r = n , mid , A= 0;
                while( l <= r ) {
                    mid = ( l + r ) >>1;
                    if( check( mid - 1 ) <= m ) {
                        A = mid; r=mid - 1;
                    }else l=  mid + 1;
                }
                ans = min( ans , A );
            }/*else {
                ll len = 0;
                for( int i = 1 ; i < n ; ++i ) {
                    //    cout <<"kkk";
                    for( int j = 1;  j < n ; ++j )
                        if( i != j ) {
                            e[U[j]].push_back( V[j] ); e[V[j]].push_back( U[j] );
                        }
                    for( int j = 1 ; j <= n ; ++j ) vis[j] = p[j] = 0 , deg[j] = v[j].size();
                    for( int j = 1 ; j<= n ; ++j )
                        if( e[j].size() == 1 )
                                qu1.push( j );
                    //for( int j = 1 ;j<= n ; ++j ) cout <<e[j].size();
                    len = 0;
                    while( qu1.size() + qu2.size() ) {
                    while( qu1.size() ) {
                        int now = qu1.size(); qu1.pop();
                        ++len;
                        if( len == n - m ) {
                            ans =min( ans , p[now] + 1 ); //cout <<now <<" ";
                        }
                        cout << now <<" ";
                        vis[now] = 1;
                        for( int j = 0 ; j < e[now].size() ; ++j )
                            if( !vis[e[now][j]] ) {
                                deg[e[now][j]] --; p[e[now][j]] = max( p[e[now][j]] , p[now] + 1 );
                                if( deg[e[now][j]] == 1  ) {
                                    ll to= e[now][j] , oo = 0;
                                    for( int k = 0 ; k< e[to].size() ; ++k ) if( !vis[e[to][k]] ) oo = 1;
                                    if( oo ) {
                                        qu2.push( e[now][j] );
                                        vis[e[now][j]] = 1;
                                    }
                                }
                            }
                    }
                    swap( qu1 , qu2 );
                    }
                    cout <<"\n";
                    for( int j = 1 ; j <= n ; ++j ) e[j].clear();
                }
            }*/
        }
        cout << ans <<"\n";
        for( int i = 0;  i <= n + 1 ; ++i ) {
            v[i].clear(); d[i] = fa[i] = q[i] = a[i] = s[i] = S = 0; ans = 0; b[i] = c[i] = sz[i] = q2[i] = st[i] = len = tt[i] = 0;
        }//ll T , n , m , S  , ans , d[maxn] , q[maxn] , fa[maxn] , s[maxn] , tot , a[maxn] , b[maxn] , c[maxn] , sz[maxn] , q2[maxn] , st[maxn] , len , tt[maxn];
//vector< int >v[maxn];
    }
    return 0;
}
