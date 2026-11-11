#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pi3 pair<int,pii>
int lowbit(int x){
    return x&-x;
}
ll n,m,a[500001],lf=1e12+1,rt=-lf,ans=1;
int flag=0;
bool check(ll x){
    ll opt=0,num=0;
    for (int i=1;i<=n;i++){
        if(a[i]>x){
            break;
        }
        opt+=x-a[i];
        if(opt>m) return false;
        num++;
    }
    ans=max(ans,num);
    return true;
}
int main(){
    cin.tie(0);cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        lf=min(a[i],lf);
        rt=max(a[i],rt);
    }
    sort(a+1,a+n+1);
    while(lf<=rt){
        ll mid=(ll) (lf+rt)>>1;
        if(check(mid)){
            lf=mid+1;
        }
        else{
            rt=mid-1;
        }
    }
    cout<<ans;
    return 0;
}