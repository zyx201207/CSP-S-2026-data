#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >> n >> m;
    vector<int> a(n+1);
    vector<int> sum(m);
    for ( int i=1;i<=n;i++ ) cin >> a[i];
    for ( int i=1;i<=n;i++ ) {
        bool flag=false;
        for ( int j=1;j<=n;j++ ) if ( a[j]!=-1 ) flag==true;
        if ( !flag ) break;
        vector<int> t(m);
        for ( int j=1;j<=n;j++ ) {
            for ( int k=i;k<=n;k++ ) 
                if ( a[j]==a[k] ) flag=false;
            if ( j<=i && flag )t[a[j]]++;
        }
        for ( int j=1;j<=m;j++ ) {
            if ( t[j]>0 ) sum[j]++;
        }
    }
    for ( int i=1;i<=n;i++ ) cout << sum[i];
    return 0;
}