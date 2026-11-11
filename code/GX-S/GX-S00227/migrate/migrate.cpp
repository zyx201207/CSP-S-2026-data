#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
int n,d;
int x[2000009],qian[2000009];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
    cin>>c>>t;
    while(t--){
        int ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>x[i];
        int ii=1,ji=1;
        for(;ii<=n&&ji<=n;ii++){
            if(x[ii]-x[ji]>d){
                    //cout<<ji<<' '<<ii<<'\n';

                while(x[ii]-x[ji]>d) qian[ji]=ii-1,ji++;
            }
            else qian[ji]=ii-1;
        }
        for(;ji<=n;ji++) qian[ji]=n;
        //for(int i=1;i<=n;i++) cout<<qian[i]<<' ';
        for(int i=1;i<n;i++){
            if(qian[i]-i>2)ans+=qian[qian[i]-1]-qian[i+1];
            else if(qian[i]-i==2) ans+=qian[i+1]-qian[i];
        }
    cout<<ans<<'\n';
    }

    return 0;
}
