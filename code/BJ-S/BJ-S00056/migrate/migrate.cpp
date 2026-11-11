#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
long long d,x[N];
int n;

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int c,t;
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        if(c==11 || c==12){
            long long yu=x[2]-x[1];
            if(d<=yu){
                cout<<0<<endl;
                continue;
            }
            long long ans=n-2*d/yu+1;
            if(ans<0){
                cout<<0<<endl;
                continue;
            }
            cout<<ans<<endl;
            continue;
        }
        cout<<0<<endl;
    }

    return 0;
}

