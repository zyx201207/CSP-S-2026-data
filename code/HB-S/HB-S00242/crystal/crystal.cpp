#include<bits/stdc++.h>
#define inf 0x3f3f3f3f3f3f3f3f
#define int long long
using namespace std;
const int maxn=5e5+50;
int n,m;
int a[maxn];
bool chk(int x){
    int cnt=0;
    int res=inf;
    for(int i=n;i>=x;i--){
        int task=a[i];
        cnt=0;
        for(int j=0;j<x;j++){
            if(i-j<=0)break;
            cnt+=(task-a[i-j]);
        }
        //cout<<"task="<<task<<" cnt="<<cnt<<endl;
        res=min(res,cnt);
    }
    if(res>m)return 0;
    else return 1;
}
void solve1(){
    sort(a+1,a+n+1);
    int l=0,r=n,mid;
    while(l<r){
        int mid=(l+r+1)/2;
        //cout<<"mid="<<mid<<endl;
        if(chk(mid)==1){
            l=mid;
        }else{
            r=mid-1;
        }
    }
    cout<<l<<endl;
    return ;
}
void solve2(){
    int t=a[3]-a[2];
    cout<<(int)((sqrt(1+(8*m/t)+1)-1)/2)+1<<endl;
    return ;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n>=100000){
        solve2();
    }else{
        solve1();
    }
    return 0;
}