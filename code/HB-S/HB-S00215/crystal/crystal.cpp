#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+10;
ll n,m;
ll a[N];
ll mx=0,mn=0x3f;
int ansmx=0;
bool FA=1;
void dfs(int now,int st,int num,ll sum){
    if(now>n){
        if(sum<=m){
            ansmx=max(ansmx,num);
        }
        return ;
    }
    dfs(now+1,st,num+1,sum+abs(st-a[now]));
    dfs(now+1,st,num,sum);
}
void solve1(){
    for(ll i=mn;i<=mx;i++){
        dfs(1,i,0,0);
    }
    cout<<ansmx;
}
void solve2(){
    int ans=0;
    for(ll i=mn;i<=mx;i++){
        vector<ll> num;
        for(ll j=1;j<=n;j++){
            num.push_back(abs(a[j]-i));
        }
        sort(num.begin(),num.end());
        ll sum=0;
        int now=0;
        while(now<n){
            if(sum+num[now]>m){
                break;
            }
            sum+=num[now];
            now++;
        }
        ans=max(ans,now);
    }
    cout<<ans;
}
void solve3(){
    ll sz2=(n+1)/2;
    ll l=1,r=sz2-1;
    ll best=-1;
    while(l<=r){
        ll mid=(l+r)/2;
        if((mid+1)*mid<=m){
            l=mid+1;
            best=mid;
        }else{
            r=mid-1;
        }
    }
    if(n%2==0&&best*(best+1)+(n-sz2)<=m){
        cout<<best*2+2;
    }else{
        cout<<best*2+1;
    }
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=i){
            FA=0;
        }
        mx=max(mx,a[i]);
        mn=min(mn,a[i]);
    }
    if(FA){
        solve3();
    }else if(mx<=20&&mn>=-20&&n<=16){
        solve1();
    }else if(n<=5000){
        solve2();
    }else{
        cout<<n;
    }
    //solve2();
    return 0;
}
