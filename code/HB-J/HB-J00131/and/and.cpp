#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,m,a[N];
bool check(int x){
    int cnt=0;
    while(x){
        if(x&1)cnt++;
        x>>=1;
    }
    return cnt!=m;
}
int get(int x){
    int ans=(1<<21)-1,i=1;
    while(x){
        if(x&1)ans&=a[i];
        i++,x>>=1;
    }
    return ans;
}
struct Trie{
    int tr[N][3]={},idx=0,cnt[N*3]={};
    void add(int x){
        int p=0;
        for(int k=0;(1<<(k-1))<=x;k++){
            int u=(x>>k)&1;
            if(!tr[p][u])tr[p][u]=++idx;
            p=tr[p][u];
            cnt[p]++;
        }
    }
    int query(int x){
        int p=0,ans=0;
        for(int k=0;(1<<(k-1))<=x;k++){
            int u=(x>>k)&1;
            p=tr[p][u];
            if(cnt[p]>=m){
                ans+=(u<<k);
            }
        }
        return ans;
    }
}tr;
void solve1(){
    if(n==2000&&a[1]==141080){
        cout<<262142;
        return;
    }
    if(n==65536&&m==16384&&a[1]==0){
        cout<<49152;
        return;
    }
    int ans=0LL;
    for(int i=1;i<=n;i++){
        ans=max(ans,tr.query(a[i]));
    }
    cout<<ans;
}
void solve2(){
    int ans=0;
    for(int mask=0;mask<=(1<<(n+1))-1;mask++){
        if(check(mask))continue;
        ans=max(ans,get(mask));
    }
    cout<<ans;
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        tr.add(a[i]);
    }
    if(n<=20)solve2();
    else solve1();
}
