//14:39
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M = 5e5+5;
int n,m,a[M];
int sum[M];
struct ST{
    int lg[M],st[22][M];
    void init(int n){
        for(int i=2;i<=n;i++)lg[i]=lg[i>>1]+1;
        for(int i=1;i<=n;i++)st[0][i]=a[i];
        for(int j=1;j<=20;j++)for(int i=1;i+(1<<j)-1<=n;i++){
            st[j][i]=max(st[j-1][i],st[j-1][i+(1<<(j-1))]);
        }
    }
    int query(int l,int r){
        int o=lg[r-l+1];
        return max(st[o][l],st[o][r-(1<<o)+1]);
    }
}S;
bool check(int mid){
    for(int i=1;i+mid-1<=n;i++){
        int mx=S.query(i,i+mid-1);
        if(mx*mid-(sum[i+mid-1]-sum[i-1])<=m)return 1;
    }
    return 0;
}
void Main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
    S.init(n);
    int l=1,r=n;
    while(l<r){
        int mid=(l+r+1)>>1;
        if(check(mid)){
            l=mid;
        }else{
            r=mid-1;
        }
    }
    cout<<l<<"\n";
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int T=1;
    while(T--)Main();
}