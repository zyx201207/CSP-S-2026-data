#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
const int M=32;
int a[N],cnt[M];
vector<int>v;
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        for(int j=0;j<=30;j++){
            if(a[i]&(1<<j)) cnt[j]++;
        }
        v.push_back(a[i]);
    }
    int ans=0;
    for(int i=30;i>=0;i--){
        if(cnt[i]<m) continue;
        vector<int>nxt;
        for(auto x:v){
            if(x&(1<<i)) nxt.push_back(x);
        }
        if(nxt.size()>=m){
            ans+=(1<<i);
            v=nxt;
        }
    }
    cout<<ans;
    return 0;
}