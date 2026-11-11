#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans;
int po[35],a[200005][35];
bool f[200005];
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    po[0]=1;
    for(int i=1;i<=30;i++){
        po[i]=po[i-1]*2;
    }
    for(int i=1,x;i<=n;i++){
        cin>>x;
        for(int j=30;j>=0;j--){
            if(x>=po[j]){
                a[i][j]=1;
                x-=po[j];
            }
        }
        f[i]=1;
    }
    for(int i=30;i>=0;i--){
        int cnt=0;
        for(int j=1;j<=n;j++){
            if(a[j][i]&&f[j])cnt++;
            //else f[j]=0;
        }
        if(cnt>=m){
            ans+=po[i];
            for(int j=1;j<=n;j++){
                if(!a[j][i])f[j]=0;
            }
        }
    }
    cout<<ans;
    return 0;
}
