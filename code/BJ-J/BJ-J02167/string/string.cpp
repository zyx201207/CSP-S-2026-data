#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,maxai,ans,sumai;
string s;
bool aisame;
struct node{
    ll num;
    char str;
};
node a[200007];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    sumai=0,maxai=0,aisame=1;
    for(ll i=1;i<=n;i++){
        cin>>a[i].num>>a[i].str;
        if(a[i].num>maxai) maxai=a[i].num;
        if(i>1){
            if(a[i].num!=a[i-1].num) aisame=0;
        }
        sumai+=a[i].num;
    }
    if(n==1){
        cout<<0;
        return 0;
    }
    if(n==2){
        if(a[1].str==a[2].str) cout<<0;
        else cout<<min(a[1].num,a[2].num);
        return 0;
    }
    if(aisame){
        ans=0;
        for(ll i=1;i<=(n+1)/2;i++){
            if(a[i].str!=a[n-i+1].str) ans+=a[i].num;
        }
        cout<<ans;
        return 0;
    }
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=a[i].num;j++){
            s+=a[i].str;
        }
    }
    ans=0;
    for(ll i=0;i<(sumai+1)/2;i++){
        if(s[i]!=s[sumai-i-1]) ans++;
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
