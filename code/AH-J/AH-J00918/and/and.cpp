#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+10;
ll n,m,maxn,sum,ans;
struct Node{
    ll zhi;
    bool ok;
}a[N];
bool check(ll x,ll y){
    string s;
    while(x){
        s+=(x%2)+'0';
        x/=2;
    }
    if(y>=s.size()||s[y]=='0')return false;
    return true;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        scanf("%lld",&a[i].zhi);
        a[i].ok=1;
        maxn=max(maxn,a[i].zhi);
        if(i==1)sum=a[i].zhi;
        else sum=((sum)&(a[i].zhi));
    }
    if(m==1){
        cout<<maxn;
        return 0;
    }
    if(m==n){
        cout<<sum;
        return 0;
    }
    if(m==2){
        for(ll i=1;i<n;i++){
            for(ll j=i+1;j<=n;j++){
                ans=max(ans,(a[i].zhi&a[j].zhi));
            }
        }
        cout<<ans;
        return 0;
    }
    for(ll wei=30;wei>=0;wei--){
        ll x=2,cnt=0;
        for(ll i=1;i<=n;i++){
            if(a[i].ok==0)continue;
            if(check(a[i].zhi,wei))cnt++;
        }
        if(cnt>=m){
            for(ll i=1;i<=n;i++){
                if(check(a[i].zhi,wei)==0)a[i].ok=0;
            }
            ans+=pow(x,wei);
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
/*
PLEASE AC!!!!!!!!
*/
