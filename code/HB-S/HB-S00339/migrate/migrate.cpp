#include<bits/stdc++.h>
using namespace std;
const int N=2000005;
int c,t,n,d,x[N]={0},ans=0;
bool check(int l,int r){
    for(int i=l+1;i<=r;i++){
        if(x[i]-x[i-1]>d)return 0;
        if(d<2*(x[i]-x[i-1]))return 0;
    }
    return 1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int e=1;e<=t;e++){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                if(check(i,j)){
                    ans++;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
