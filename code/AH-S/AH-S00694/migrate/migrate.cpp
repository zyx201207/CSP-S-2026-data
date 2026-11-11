#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
long long c,t,n,d,a[N];
int main(){
    ios::sync_with_stdio();
    cin.tie();cout.tie();
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>a[i];
        if(c==0||c==11||c==12){
            long long dd=d/(a[2]-a[1]);
            if(dd==0||dd==1||n<(2*dd-1))cout<<0<<"\n";
            else cout<<n-(2*dd-1)<<"\n";
        }
        if(c==13||c==14){
            long long xx,ans=0;
            for(int i=1;i<=n;i++)
                if(a[i]-a[1]<=d&&a[n]-a[i]<=d){
                    xx=i;
                    break;
                }
            for(int i=1;i<xx;i++){
                for(int j=n;j>xx;j--){
                    if(a[j]-a[xx-1]<=d){
                        if(a[j]-a[xx-2]<=d)break;
                        else ans++;
                    }
                }
            }
            cout<<ans<<"\n";
        }
    }
    return 0;
}
