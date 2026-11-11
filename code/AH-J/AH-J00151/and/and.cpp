#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200001];
bool vis[200001];
ll digits[31];
ll pows_2[32]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,2147483647};
priority_queue<ll> pq[31];
ll maxn=0;
ll n,m;
void dfs(ll depth,ll cur){
    if(depth==m){
        maxn=max(maxn,cur);
        return;
    }
    for(ll i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            dfs(depth+1,cur&a[i]);
            vis[i]=0;
        }
    }
}
void solve1(){
    dfs(0,2147483647);
    cout<<maxn;
}
void solve2(){
    if(m==1){
        for(ll i=1;i<=n;i++){
            maxn=max(maxn,a[i]);
        }
    }
    else if(m==2){
        for(ll i=1;i<=n;i++){
            for(ll j=i+1;j<=n;j++){
                maxn=max(maxn,a[i]&a[j]);
            }
        }
    }
    else if(m==n){
        maxn=2147483647;
        for(ll i=1;i<=n;i++){
            maxn&=a[i];
        }
    }
    cout<<maxn;
}
void solve3(){
    for(ll i=1;i<=n;i++){
		ll t=a[i];
        for(ll j=30;j>=0;j--){
            if(t>=pows_2[j]){
                digits[j]++;
                pq[j].push(a[i]);
                //cout<<j<<' '<<a[i]<<endl;
                t-=pows_2[j];
            }
        }
    }
    maxn=0;
    for(ll i=30;i>=0;i--){
		//cout<<i<<' '<<digits[i]<<endl;
        if(digits[i]>=m){
            maxn=2147483647;
            for(ll j=1;j<=m;j++){
                ll x=pq[i].top();
                pq[i].pop();
                //cout<<x<<endl;
                maxn&=x;
            }
            break;
        }
    }
    cout<<maxn;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=20){
        solve1();
    }
    else if(n<=2000){
        solve2();
    }
    else{
        solve3();
    }
    return 0;
}
