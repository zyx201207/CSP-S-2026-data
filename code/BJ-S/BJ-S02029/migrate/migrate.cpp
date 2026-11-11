#include<bits/stdc++.h>
using namespace std;
int c,t;
long long x[2000006];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        long long n,d,ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        sort(x+1,x+1+n);
        long long l=1,r=4,a=2;
        while(r<=n){
            if(r-l<3){
                r=l+3;
                continue;
            }
            while(x[r]-x[l]<=d&&r<=n){
                r++;
            }
            while(x[r]-x[a-1]<=d&&r<=n){
                r++;
            }
            while(x[a+2]-x[l]<=d&&a<=r){
                a++;
            }
            while(x[r]-x[a]>d&&a<=r){
                a++;
            }
            while(x[a+1]-x[l]>d&&l<=a){
                l++;
            }
            if(x[a+1]-x[l]<=d&&x[r]-x[a]<=d&&x[a+2]-x[l]>d&&x[r]-x[a-1]>d&&x[r]-x[l]>d){
                ans++;
                r++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
