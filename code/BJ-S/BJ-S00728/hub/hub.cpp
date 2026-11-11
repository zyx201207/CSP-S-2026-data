#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,k,n,m;
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        if(n-k==4){
            cout<<2<<endl;
        }
        else if(n-k==3){
            if(n==4){
                cout<<2<<endl;
            }
            else{
                cout<<1<<endl;
            }
        }
        else if(n-k==2){
            cout<<1<<endl;
        }
        else if(n-k==1){
            cout<<1<<endl;
        }
        else{
            cout<<0<<endl;
        }
    }
    return 0;
}
