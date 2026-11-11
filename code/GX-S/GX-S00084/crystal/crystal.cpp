#include<bits/stdc++.h>
using namespace std;
using ll=long long ;
const ll N=5e5+10,M=1e12-10;
ll n,m,a[N],c[N],ans=0;
ll flag,sum=0,cnt=0;
bool cmp(ll x,ll y){
    return x<y;
}
int main (){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin>>n>>m;

    if(m<=M){
        for(ll i=0;i<n;i++){
            cin>>a[i];
            /*if(i==0){
                c[i]=0;
            }else {
                c[i]=abs(a[i]-a[i-1]);
            }*/
        }
        sort (a,a+n,cmp);
        for(ll i=1;i<n;i++){
            sum=0,cnt=1;
            for(ll j=i-1;j>=0;j--){
                //<<a[j]<<' ';
                sum+=a[i]-a[j];
                if(sum>m)break;
                cnt++;
            }
            //<<"--"<<sum<<"+++"<<cnt<<endl;
            ans=max(cnt,ans);
        }
        cout<<ans;
        return 0;
    }else {
        ll sum=0,cnt=0;
        for(ll i=0;i<2;i++){
            cin>>a[i];
        }
        ll x=abs(a[1]-a[2]);
        cout<<m/x;
        return 0;
    }
    return 0;
}
