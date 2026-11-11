#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6*2+10;
unsigned int c,t,ans[N];
int n,d,x[N];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>d;
        for(int j=1;j<=n;j++){
            cin>>x[j];
        }
        int t=x[2]-x[1];
        int s=d/t;
        for(int j=1;j<=n;j++){
            for(int k=j+1;k<=n;k++){
                int len=x[k]-x[j];
                if(len%s==(d-1)&&len/s>0)ans[i]++;
            }
        }
    }
    for(int i=1;i<=t;i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}
