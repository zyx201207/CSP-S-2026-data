#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

int C,T;
ll a[5005],n,d;
int g[5005][5005],f[5005][5005];

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>C>>T;
    while(T--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        if(n==1 or n==2 or n==3){
            cout<<"0\n";
            continue;
        }
        if(1){
            ll gc=a[2]-a[1];
             //   cout<<gc<<" "<<n<<"\n";
            if(gc*2>d){
                cout<<"0\n";
                continue;
            }
            cout<<max((ll)0,n-(d/gc)*2)<<"\n";
        }
    }
    /*
    cin>>n>>d;
    memset(g,0x3f,sizeof(g));
    for(int i=1;i<=n;i++){
        cin>>a[i];
        g[i][i]=0;
    }
    if()
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            if(a[j]-a[i]<=d){
                g[i][j]=g[j][i]=1;
                f[i][j]=f[j][i]=1;
            }
            else{
                break;
            }
        }
    }
    */
    return 0;
}

