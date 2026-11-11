#include <bits/stdc++.h>
using namespace std;
const int MAXN=200005;

int n,m,dp[MAXN][MAXN][2][2],a[MAXN],ans=1;

int nand(int a,int b){
    int ans=0;
    if(a>b)swap(a,b);
    for(i=0;pow(2,i)<=a;i++){
        ans+=pow(2,(a/pow(2,i)%2)&(b/pow(2,i)%2));
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){int tmp;cin>>tmp;ans&=tmp;}
    cout<<ans;
    return 0;
}

// standard method: beibao+zhuangtaiyasuo dp
// start: 9:31
