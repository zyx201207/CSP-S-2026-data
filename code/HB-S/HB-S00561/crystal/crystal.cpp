#include<bits/stdc++.h>
using namespace std;
using ll=long long;
inline ll read(){
    ll x=0,f=1;
    int c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
inline void print(ll x){
    if(x<0){putchar('-');x=-x;}
    if(x>9)print(x/10);
    putchar(x%10+'0');
}
const int maxn=5e5+5;
ll n,m,a[maxn],ml=0;
int cnt[maxn],ans=0;
map<ll,int>mp;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=read();m=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
        mp[a[i]]++;
    }
    sort(a+1,a+n+1);
    int len=unique(a+1,a+n+1)-a-1;
    int idx=1;
    ans=mp[a[1]];
    cnt[1]=mp[a[1]];
    int j=1;
    for(int i=2;i<=len;i++){
        ml+=(ll)ans*(a[i]-a[i-1]);
        while(ml>m&&i>idx){
            ml-=(ll)(a[i]-a[idx]);
            ans--;
            if(j==mp[a[idx]]){
                idx++;
                j=1;
            }
            else{
                j++;
            }
        }      
        ans+=mp[a[i]];
        cnt[i]=ans;  
    }
    int mx=0;
    for(int i=1;i<=len;i++){
        mx=max(mx,cnt[i]);
    }
    print(mx);
    return 0;
}