#include<bits/stdc++.h>
using namespace std;

long long c,T,n,d,x[2000005];

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>c>>T;
    while(T--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        if(c==11||c==12){

            if(d<(x[2]-x[1])*2){
                cout<<0<<'\n';
            }
            else{
                cout<<max(n-(long long)(d/(x[2]-x[1]))*2+1,0ll)<<'\n';
            }
        }
        else{
            cout<<0<<'\n';
        }
    }

    return 0;

}
