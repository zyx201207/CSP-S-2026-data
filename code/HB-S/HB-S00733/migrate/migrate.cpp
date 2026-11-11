#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N=2e6+5;
ll a[N];

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;cin>>c>>t;
    while(t--){
        int n;ll d;cin>>n>>d;
        for(int i=1; i<=n; i++) cin>>a[i];
        if(n<=3 || a[n]-a[1]<=d){
            cout<<"0\n";
            continue;
        }
        if(c==11 || c==12){
            ll dd=a[2]-a[1];ll k=d/dd;
            if(k<=1){
                cout<<"0\n";
                continue;
            }
            cout<<max(n+1-2*k,0ll)<<"\n";
            continue;
        }
        if(c==13 || c==14){
            int k=0,z=0,y=0,cn=0;
            for(int i=1; i<=n; i++) if(a[i]-a[1]<=d && a[n]-a[i]<=d) k=i,cn++;
            if(cn>=3){
                cout<<"0\n";
                continue;
            }
            if(cn==2){
                for(z=1; z<k; z++) if(a[k+1]-a[z]<=d){z--;break;}
                for(y=n; y>k; y--) if(a[y]-a[k-2]<=d){y++;break;}
                cout<<1ll*(n-y+1)*z<<"\n";
                continue;
            }
            ll ans=0;
            if(a[k+1]-a[k-1]<=d){
                if(a[k+1]-a[k-2]>d) ans+=k-2;
                if(a[k+2]-a[k-1]>d) ans+=n-(k+2)+1;
            }
            for(int i=1; i<k-1; i++) if(a[k+1]-a[i]<=d) z++;
            for(int i=k+2; i<=n; i++) if(a[i]-a[k-1]<=d) y++;
            cout<<ans+1ll*z*(n-(k+2)+1-y)+1ll*y*(k-2-z)<<"\n";
            continue;
        }
    }
    return 0;
}
//17:57 16
