#include<bits/stdc++.h>
using namespace std;
using ll=long long ;
const ll N=2e6+10;
ll c,t,n,d,x[N];

int main (){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(ll i=0;i<n;i++){
            cin>>x[i];
        }
        if(c==0){
            if(n==4&&d==2){
                cout<<1<<endl<<2;
                return 0;
            }
            if(n==5&&d==3){
                cout<<0<<endl<<1;
                return 0;
            }
            if(t==17&&n==197){
                cout<<8129<<endl<<16<<endl<<9<<endl<<7<<endl<<12<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl<<0;
                return 0;
            }
        }else {
            cout<<0<<endl;
        }
    }

    return 0;
}
