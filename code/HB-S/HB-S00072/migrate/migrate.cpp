#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n,d,ans=0;
        cin>>n>>d;
        int x[N];
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        int mp[N][N];
        for(int i=1;i<=n;i++){
            mp[1][i]=0,mp[2][i]=1;
            for(int j=i+2;j<=n;j++){
                for(int k=j-d;k<j;k++){
                    mp[j][i]+=mp[k][i];
                }
                if(mp[j][i]==2)ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
