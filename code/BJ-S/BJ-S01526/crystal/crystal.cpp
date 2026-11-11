#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
    int val,id;
}c[500010];
int n,k,a[500010],q[500010],z,ans;
bool cmp(node a,node b){return a.val<b.val;}
int ca(int t,int l,int id){return t*(l-1)-q[id-1]+q[id-l];}
bool check1(){
    int k=a[2]-a[1];
    for(int i=3;i<=n;i++)if(a[i]-a[i-1]!=k)return 0;
    return 1;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    if(check1()){
        int D=a[2]-a[1];
        for(int i=0;;i+=D){
            if(k>=i)ans++,k-=i;
            else{cout<<min(n,ans);return 0;}
        }
    }
    for(int i=1;i<=n;i++)q[i]=q[i-1]+a[i];
    for(int i=2;i<=n;i++)c[i].val=a[i]-a[i-1],c[i].id=i;
    sort(c+2,c+n+1,cmp);
    for(int i=2;i<=n;i++){
        for(int j=c[i].id-1;j>=1;j--){
            int d=ca(a[c[i].id],c[i].id-j+1,c[i].id);
            if(k>=d)ans=max(ans,c[i].id-j+1);
        }
    }
    cout<<ans;
    return 0;
}
