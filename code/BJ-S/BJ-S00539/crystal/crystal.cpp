#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long
typedef long long ll;
const int N=5e5+5;
int n;
ll m,a[N],s[N];
int c[205],b[205],_n;
int chk(ll d,int a[],int ni){
    ll res=m;
    if(d<a[1])return 0;
    int l=lower_bound(a+1,a+ni+1,d)-a,r=upper_bound(a+1,a+ni+1,d)-a,cnt;
    cnt=r-l;
    for(int i=l-1;i>=1;i--){
        if((d-a[i])<=res){
            res-=(d-a[i]);
            cnt++;
        }
        else break;
    }
    return cnt;
}
void doit1(){
    int ans=0;
    for(int i=1;i<=n;i++){
        if(a[i]==a[i-1])continue;
        ans=max(ans,chk(a[i],a,n));
    }
    cout<<ans;
}
int chk1(ll d,int j){
    ll res=m;
    if(d<b[1])return 0;
    int cnt=0;
    for(int i=j-1;i>=1;i--){
        if((d-a[i])<=res){
            int k=res/(d-b[i]);
            k=min(k,c[b[i]+100]);
            res-=(d-b[i])*k;
            cnt+=k;
        }
        else break;
    }
    return cnt;
}
void doit2(){
    for(int i=1;i<=n;i++){
        c[a[i]+100]++;
        if(a[i]!=a[i-1])b[++_n]=a[i];
    }
    int ans=0;
    for(int i=1;i<=_n;i++){
        //cout<<b[i]<<" "<<c[b[i]+100]<<"\n";
        ans=max(ans,c[100+b[i]]+chk1(b[i],i));
    }
    cout<<ans;
}
void doit3(){
    int ans=0;
    if(a[1]==a[2]){
        cout<<n;
        return ;
    }
    for(int i=1;i<=n;i++){
        int res=0,l=0,r=i-1;
        __int128 d=a[i]-a[i-1];
        while(l<=r){
            __int128 mid=(l+r)/2;
            __int128 clc=mid*(mid+1)/2*d;
            if(clc<=m){
                res=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        ans=max(ans,res+1);
    }
    cout<<ans;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    a[0]=-1e18;
    if(a[1]>=-100&&a[n]<=100){
        doit2();
    }
    else if(n<=5000)doit1();
    else doit3();
    return 0;
}
