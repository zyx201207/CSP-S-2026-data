#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef __int128 i128;
typedef unsigned __int128 u128;
ll x[2145140];
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,T;
    cin>>c>>T;
    while(T--){
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>x[i];
        if(d/(x[2]-x[1])!=2)cout<<0<<'\n';
        else cout<<n-3<<'\n';
    }
    return 0;
}