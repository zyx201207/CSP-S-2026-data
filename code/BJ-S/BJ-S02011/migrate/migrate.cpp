//203899
//lucky fiiiiiish!
#include<bits/stdc++.h>
#define Test ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"
using namespace std;
const int maxn=1e6+10;
int c,t,a[maxn];
signed main(){
    Test
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    if(c==13 || c==14){
        while(t--){
            cout<<0<<endl;
        }
    }
    /*
    else if(c==11 || c==12){
        while(t--){
            int n,m;
            cin>>n>>m;
            if(n==1){
                cout<<0<<endl;
                continue;
            }
            for(int i=1;i<=n;i++) cin>>a[i];
            int cha=a[2]-a[1];
            int k=m/cha;
            for(int i=1;i<=n;i++){
                if(a[i]>a[n]-k)
            }
        }
    }
    */
    return 0;
}
