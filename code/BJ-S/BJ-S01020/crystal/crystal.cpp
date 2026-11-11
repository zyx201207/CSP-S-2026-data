#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll n,m,a[N],sum,maxx=-1,o;
map<int ,int>mp;
struct node{
    ll id,a;
}b[N];
struct node2{
    ll id,a;
}dp[1000][20000];
bool cmp(node x,node y){
    return x.a<y.a;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;

    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(ll i=2;i<=n;i++){
        b[i-1].a=a[i]-a[i-1];
        b[i-1].id=i;
        sum+=a[n]-a[i-1];
    }
    if(sum<=m||n>1000||m>20000){
        cout<<m;
        return 0;
    }
    for(ll i=1;i<=n;i++){
        mp[a[i]]++;
    }
    for(ll i=1;i<=n;i++){
        ll x=mp[a[i]];
        if(maxx<x){
            maxx=x;
            o=a[i];
        }
    }
    ll temp=0;
    for(ll i=1;i<=n;i++){
        if(a[i]==o)
            temp++;
        if(temp>=2){
            dp[i][0].a=temp;
            dp[i][0].id=o;
        }
    }
    for(ll i=2;i<=n;i++){
        sort(b+1,b+i+1,cmp);
        for(ll j=1;j<=m;j++){
            if(dp[i][j-1].a>dp[i-1][j].a){
                dp[i][j].a=dp[i][j-1].a;
                dp[i][j].id=dp[i][j-1].id;
            }
            else if(dp[i][j-1].a<=dp[i-1][j].a&&dp[i-1][j].a>0){
                dp[i][j].a=dp[i-1][j].a;
                dp[i][j].id=dp[i-1][j].id;
            }/*
            if(dp[i][j-1].a>0&&dp[i-1][j].a>0&&dp[i-1][j].id==dp[i][j-1].id){
                dp[i][j].a=dp[i][j-1].a+dp[i-1][j].a-1;
                dp[i][j].id=dp[i-1][j].id;
            }*/
            ll x=j;/*
            for(int k=i;k>=1;k--){
                if(a[i]<dp[i][j].id&&dp[i][j].id-a[i]<=x){
                    dp[i][j].a++;
                    x-=(dp[i][j].id-a[i]);
               }
            }*/
            x=j;
            ll flag=0;
            for(ll k=i-1;k>=1;k--){
                if(a[i]-a[k]<=x){
                    if(!flag)flag=2;
                    else flag++;
                    x-=(a[i]-a[k]);
                }
            }
            if(dp[i][j].a<flag){
                dp[i][j].a=flag;
                dp[i][j].id=a[n];
            }
            //cout<<dp[i][j].a<<" ";
        }
        //c/out<<endl;
    }
    cout<<dp[n][m].a;
    return 0;
}
