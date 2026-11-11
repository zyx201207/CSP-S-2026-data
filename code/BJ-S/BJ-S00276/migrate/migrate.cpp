#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+5;
ll a[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n,d;
        cin>>n>>d;
        int ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=i+d+1;j<=n;j++){
                int p=(j-i)/d;
                p-=2;
                int s1=1;
                int s2=1;
                for(int k=(j-i-1),sum=1;sum<=p;sum++,k--){
                    s1*=k;
                }
                for(int k=p;k>=1;k--){
                    s2*=k;
                }
                if((s1/s2)==2) ans++;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}