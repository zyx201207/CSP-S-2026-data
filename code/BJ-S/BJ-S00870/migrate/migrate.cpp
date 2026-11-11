#include<bits/stdc++.h>
using namespace std;
#define int long long
int C,T;
int n,d;
const int maxn=2e6+10;
int a[maxn];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> C >> T ;
    while(T--){
        cin >> n >> d ;
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++){
            cin >>a[i] ;
        }
        int del=a[2]-a[1];
        int tim=d/del;
        if(tim<=1){
            cout << 0 << '\n' ;
        }
        else {
            tim=tim*2-1;
            tim=n-tim;
            if(tim<0)tim=0;
            cout << tim <<'\n' ;
         }
    }
    return 0;
}
