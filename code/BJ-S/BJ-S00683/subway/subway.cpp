#include<bits/stdc++.h>
using namespace std;
const int N=50005;
int c,t,n;
long long d,a[N],ans;
map<long long,bool> m;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    if(c!=11&&c!=12){
        while(t--){
            cin>>n>>d;
            ans=0;
            for(int i=1;i<=n;i++){
                cin>>a[i];
                m[a[i]]=true;
            }
            for(int i=1;i<=n;i++){
                for(int j=i;j<=n;j++){
                    if(abs(a[j]-a[i])!=2*d+1)continue;
                    else{
                        bool k1=0,k2=0,k3=0,k4=0;
                        for(int k=i;k<=j;k++){
                            if(a[k]==a[i]+1)k1=true;
                            if(a[k]==a[i]+d)k2=true;
                            if(a[k]==a[i]+d+1)k3=true;
                            if(a[k]==a[i]+2*d)k4=true;
                        }
                        if((k1&&k4)||(k2||k3))ans++;
                    }
                }
            }
            cout<<ans<<'\n';
        }
    }
    else{
        while(t--){
            cin>>n>>d;
            for(int i=1;i<=n;i++){
                cin>>a[i];
            }
            if(a[2]-a[1]>=d)cout<<"0\n";
            else{
                if((2*d+1)%(a[2]-a[1])==0){

                }
            }
        }
    }
    return 0;
}
