#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
int a[N];
int b[N][N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,T;
    cin>>c>>T;
    int n,d,ans=0;
    while(T--){
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                b[i][j]=0;
            }
        }
        ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n-2;i++){
            for(int j=a[i+1];j<=n-1;j++){
                if(a[j]-a[i]>d) continue;
                for(int k=a[j+1];k<=n;k++){
                    if(a[k]-a[j]>d) continue;
                    b[i][k]++;
                }
            }
        }
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                if(b[i][j]==2) ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
