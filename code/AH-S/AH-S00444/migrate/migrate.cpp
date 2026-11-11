#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,t,k,a[1000005],d[1000005],sum,maxn=-0x3f3f3f3f3f3f3f3f;
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>m>>t;
    while(t--){
        int cnt=0;
        cin>>n>>k;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        if(m<=10){
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    if((a[j]-a[i])/k==1&&(a[j]-a[i])%k!=0){
                        cnt++;
                    }
                }
            }
            cout<<cnt<<endl;
        }else{
            int d=a[2]-a[1];
            k/=d;
            if(k<=1){
                cout<<0;
            }else{
                cout<<n-(k*2)+1;
            }
        }

    }

    return 0;
}
