#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,xo[35],x,ans=pow(2,30)-1;
struct node{
    ll val;
    bool o[35]={0};
    bool operator<(const node b)const{
        return val>b.val;
    }
}a[200005];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>x;ll j=0;a[i].val=x;
        while(x){
            xo[j]+=x%2,a[i].o[j++]=x%2;
            x/=2;
        }
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n&&m>0;i++){
        for(int j=29;j>=0;j--){
            if(a[i].o[j]&&xo[j]>=m){
                for(int k=29;k>=0;k--) xo[k]-=a[i].o[k];
                ans&=a[i].val,--m;
                break;
            }
        }
    }
    cout<<ans;
    return 0;
}
