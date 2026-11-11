#include<bits/stdc++.h>
using namespace std;
const int N=5090;
int ceshi,T;
long long n,d;
long long mp[N][N];
long long a[N],ans;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>ceshi>>T;
    while(T--){
        cin>>n>>d;
        ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                mp[i][j]=(a[j]-a[i])/d+((a[j]-a[i])%d!=0);
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                if(d*(mp[i][j])-1==a[j]-a[i]&&j-i>1){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
