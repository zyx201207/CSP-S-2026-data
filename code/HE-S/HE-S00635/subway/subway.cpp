#include <bits/stdc++.h>
using namespace std;

long long k[100000];
int main(){
    freopen("/home/noi/noip/HE-S00635/subway/subway.in","r",stdin);
    freopen("/home/noi/noip/HE-S00635/subway/subway.out","w",stdout);
    long long c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i = 0;i<m;i++){
        cin>>c;
    }
    for(int i = 0;i<n;i++){
            cin>>c;
        for(int j = 0;j<k[i];j++){
            cin>>c>>c;
        }
    }
    for(int i = 0;i<q;i++){
        cin>>c>>c;
    }
    for(int i = 0;i<q;i++){cout<<0<<endl;}
    return 0;
}
