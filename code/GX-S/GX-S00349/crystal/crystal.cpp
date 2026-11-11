#include<bits/stdc++.h>
#define inf 0x3f3f3f3f3f
#define c(x) cout<<x<<endl
#define fet(x) const int fet=x

#define int long long

using namespace std;

fet(5e5+10);
int n,m,ans=-inf;
int a[fet];
int ma=-inf;

int s[fet];
bool c_(int x){
    for(int i=1;i<=n;i++){
        s[i]=abs(a[i]-x);
    }
    sort(s+1,s+1+n);
    int sum=0,cnt=0;
    for(int i=1;i<=n;i++){
        if(sum+s[i]<=m) sum+=s[i],cnt++;
        else break;
    }
    if(cnt){
        ans=max(ans,cnt);
        return true;
    }else return false;
}

void solve2();


signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ma=max(ma,abs(a[i]));
    }
    sort(a+1,a+1+n);
    if(n>5000&&m>100000000) solve2();
    else{
        int l=-ma,r=ma;
        while(l<r){
            int mid=(l+r)>>1;
            if(c_(mid)){
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        c(ans);
    }
    return 0;
}

void solve2(){
    int deta=abs(a[2]-a[1]);
    for(int i=2;i<=n;i++){
        int sum=i/2*(i-1)*deta;
        if(i&1) sum+=(i-1)*deta/2;
        if(m>=sum) ans=i;
    }
    c(ans);
}
