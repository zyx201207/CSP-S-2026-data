#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    int a[500001]={};
    while(t--){
        int n,d;
        int flag=false;
        cin>>n>>d;
        if(d>2){
            cout<<0<<endl;
            flag=true;
        }
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int ans=0;
        for(int i=1;i<=n-3;i++){
            if((a[i+1]-a[i]<=d&&a[i+3]-a[i+1]<=d)&&(a[i+2]-a[i]<=d&&a[i+3]-a[i+2]<=d)){
                    if(n-4>=i){
                        if(a[i+4]-a[i]>=d){
                            ans++;
                        }
                    }
                    else ans++;

            }
        }
        if(flag==false)
            cout<<ans<<endl;
    }

    return 0;
}

