#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[201010][35],ans,jl[35],b[201010];
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int x,cnt=0;
        cin>>x;
        while(x){
            if(x%2==1){
                a[i][cnt]=1;
                jl[cnt]++;
            }
            cnt++;
            x/=2;
        }
    }
    for(int i=33;i>=0;i--){
        if(jl[i]<m)continue;
        for(int j=1;j<=n;j++){
            if(!b[j]&&!a[j][i]){
                b[j]=1;
                for(int k=0;k<=33;k++){
                    if(a[j][k])jl[k]--;
                }
            }

        }
        ans+=pow(2,i);
    }
    cout<<ans;
    return 0;
}
