#include<bits/stdc++.h>
using namespace std;
int a[2000010];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    int n,d;
    while(cin>>n>>d){
        int ans=0;
        for(int i=1;i<=2000000;i++){
            a[i]=0;
        }
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n-3;i++){
            int j=i+3;
            int s=0;
            if(a[i+1]-a[i]<=d){
                if(a[i+3]-a[i+1]<=d){
                    s++;
                }
            }
            if(a[i+2]-a[i]<=d){
                if(a[i+3]-a[i+2]<=d){
                    s++;
                }
            }
            if(s>=2){
                ans++;
                //cout<<i<<" "<<j<<"\n";
            }

        }
        cout<<ans<<"\n";
    }
    return 0;
}
