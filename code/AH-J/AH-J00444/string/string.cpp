#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=200005,mx=2100000000;
ll a[N],b[N]={1},n,m=0,ans=0;
char d[mx];
string c[N];
ll fzh(ll x){
    return m-x+1;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i]>>c[i],m+=a[i];
    if(m>mx){
        for(int i=1;i<=n+1;++i) b[i]=b[i-1]+a[i-1];
        ll l=1,r=n;
        bool sdks=0;//谁的开始:0l,1r
        while(l!=r){
            if(sdks==0){//l是新的
                if(fzh(b[r])<b[l+1]-1){//l比r长
                    sdks=1;
                    if(c[l]!=c[r]) ans+=abs(fzh(b[r])-b[l]+1);
                    --r;
                }else if(fzh(b[r])>b[l+1]-1){//r比l长
                    sdks=0;
                    if(c[l]!=c[r]) ans+=a[l];
                    ++l;
                }else{
                    sdks=0;
                    if(c[l]!=c[r]) ans+=abs(fzh(b[r])-b[l]+1);
                    --r,++l;
                }
            }else{//r是新的
                if(fzh(b[r])<b[l+1]-1){//l比r长
                    sdks=1;
                    if(c[l]!=c[r]) ans+=a[r];
                    --r;
                }else if(fzh(b[r])>b[l+1]-1){//r比l长
                    sdks=0;
                    if(c[l]!=c[r]) ans+=abs(b[l+1]-fzh(b[r+1]-1));
                    ++l;
                }else{
                    sdks=0;
                    if(c[l]!=c[r]) ans+=abs(fzh(b[r])-b[l]+1);
                    --r,++l;
                }
            }
        }
        cout<<ans;
    }else{
        ll qq=1;
        for(int i=1;i<=n;++i){
            for(int j=qq+a[i];qq<j;++qq){
                d[qq]=c[i][0];
            }
        }
        for(int i=1;i<=m/2;++i){
            if(d[i]!=d[m-i+1]) ++ans;
        }
        cout<<ans;
    }
    return 0;
}
