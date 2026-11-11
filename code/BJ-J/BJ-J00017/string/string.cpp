#include <bits/stdc++.h>
using namespace std;

const int N=2e5+10;

typedef long long ll;
ll n,a[N],p[N],sum[N][26];
char c[N];
ll ans;

int find(ll x){
    int l=1,r=n,ans=-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(p[mid]>=x){
            ans=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    return ans;
}

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
    for(int i=1;i<=n;i++){
        p[i]=p[i-1]+a[i];
        for(int j=0;j<26;j++){
            char t='a'+j;
            if(c[i]!=t){
                sum[i][j]=sum[i-1][j]+a[i];
            }else{
                sum[i][j]=sum[i-1][j];
            }
        }
    }
    for(int i=1;i<=n;i++){
        ll l=p[i-1]+1,r=p[i];
        ll fl=p[n]-r+1,fr=p[n]-l+1;
        ll p1=find(fl),p2=find(fr);
        if(p1==p2 && c[p1]!=c[i]){
            ans+=fr-fl+1;
            continue;
        }else if(p1==p2){
            continue;
        }
        if(c[p1]!=c[i]){
            ans+=p[p1]-fl+1;
        }
        if(c[p2]!=c[i]){
            ans+=fr-p[p2-1];
        }
        if(p1+1!=p2){
            ans+=sum[p2-1][c[i]-'a']-sum[p1][c[i]-'a'];
        }
    }
    cout<<ans/2;
}
