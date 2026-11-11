#include<bits/stdc++.h>
using namespace std;
using ll =long long ;
const int N=2e5+10;
ll n,m;
ll a[N];
bool cmp(ll x,ll y){
    return x>y;
}
void dfs(){
    ll ans=0,sum,flag=0;
    for(ll i=0;i<(1<<n);i++){
        sum=0;
        flag=0;
        for(ll j=0;j<n;j++){
            //cout<<i<<' '<<j<<endl;
            if((i&(1<<j))){
                if(flag==0){
                    sum=a[j];
                }else {
                    if(flag<=m){
                        sum=sum&a[j];
                    }
                }
                flag++;
            }//cout<<sum<<endl;
        }
        if(flag==m)ans=max(sum,ans);
    }
    cout<<ans;
    return ;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie (0);
    cout.tie(0);

    freopen ("and.in","r",stdin);
    freopen ("and.out","w",stdout);

    cin>>n>>m;
    for(ll i=0;i<n;i++) cin>>a[i];
    if(n<=20){
        dfs();
        return 0;
    }else{
        sort(a,a+n,cmp);
        ll ans =a[0];
        for(ll i=1;i<m;i++){
            ans=ans&a[i];
        }
        cout<<ans;
        return 0;
    }
    return 0;
}
