#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll m;
ll a[500100];
ll ans=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    int id=1;
    for(int i=ceil(n/2.0);i>=1;i--){
        m-=a[(int)ceil(n/2.0)]-a[i];
        if(m<0){
            m+=a[(int)ceil(n/2.0)]-a[i];
            id=i;
            break;
        }
        ans++;
    }
    for(int i=ceil(n/2.0)+1;i<=n;i++){
        m-=(i-id)*(a[i]-a[i-1]);
        if(m<0){
            break;
        }
        ans++;
    }
    cout<<ans;
    return 0;
}
//duo_gei_dian_fen_ba qwq
//qiu_qiu_ni_la qwq qwq
//qwq qwq