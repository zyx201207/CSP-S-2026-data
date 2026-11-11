#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+7;
char c[N];
string s1,s2;
ll n,a[N],sum=0,rm=0,k=0,ans=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        sum+=a[i];
    }
    ll m;
    if(sum%2==0){
        m=sum/2+1;
    }else{
        m=sum/2+2;
    }
    while(k<m){
        rm++;
        k+=a[rm];
    }
    for(ll i=m;i<=k;i++){
        s1+=c[rm];
    }
    for(ll i=rm+1;i<=n;i++){
        for(ll j=1;j<=a[i];j++){
            s1+=c[i];
        }
    }
    for(ll i=1;i<=rm-1;i++){
        for(ll j=1;j<=a[i];j++){
            s2+=c[i];
        }
    }
    for(ll i=k-a[rm]+1;i<=m-1;i++){
        s2+=c[rm];
    }
    long long sz=s1.size();
    for(ll i=0;i<sz;i++){
        if(s1[sz-1-i]!=s2[i]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}