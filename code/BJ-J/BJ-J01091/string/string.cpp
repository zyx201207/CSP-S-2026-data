#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
using namespace std;

typedef long long ll;
ll n,a[200005],ans,b;
string s;
char c[200005];
void pow1(ll l,ll r){
    if(l>r){
        return ;
    }
    char l1=s[l],r1=s[r];
    if(l1==r1){
        pow1(l+1,r-1);
    }else{
        ans++;
        pow1(l+1,r-1);
    }
    return ;
}
void pow2(ll b,ll d,ll r,ll l){
    ll l1=a[l],r1=a[r];
    if(d>b/2){
        return ;
    }
    ll mi=min(l1,r1),ma=max(l1,r1);
    if(c[r]!=c[l]){
        ans=ans+mi;
    }
    if(l1<r1){
        a[r]-=mi;
        pow2(b,d+mi,r,l+1);
    }else{
        a[l]-=mi;
        pow2(b,d+mi,r-1,l);
    }
    return ;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cin>>c[i];
        for(int j=1;j<=a[i];j++){
            s+=c[i];
        }
        b+=a[i];
    }
    pow1(0,b-1);
    //pow2(b,0,n,1);
    cout<<ans;
    return 0;
}

