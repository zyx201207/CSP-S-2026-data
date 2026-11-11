#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,c,a[200010],ans;
bool b[200010][35],can[200010];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    for(ll i=1;i<=n;i++){
        for(ll j=0;j<=31;j++){
            if((a[i]>>j)&1){
                b[i][j]=1;
            }
        }
    }
    for(ll i=31;i>=0;i--){
        c=0;
        for(ll j=1;j<=n;j++){
            if(can[j]){
                continue;
            }
            if(b[j][i])c++;
        }
        if(c>=m){
            for(ll j=1;j<=n;j++){
                if(can[j])continue;
                if(!b[j][i])can[j]=1;
            }
            ans+=1<<i;
        }
//        cout<<c<<endl;
    }
    cout<<ans;
    return 0;
}
