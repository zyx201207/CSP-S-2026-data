#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[200050],mid,s,p,pos,lp,rp;
vector<int> na;
char c[200050];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i]>>c[i],s+=a[i];
    mid=(s+1)/2;
    for(int i=1;i<=n;i++){
        p+=a[i];
        if(p>=mid){
            pos=i;
            break;
        }
    }
    string l,r;
    if(s&1){
        ll sm=0,lsp=0;
        for(int i=1;i<=pos;i++){
            bool ok=0;
            for(int j=1;j<=a[i];j++){
                l+=c[i];
                sm++;
                if(sm==mid-1){
                    lsp=j;
                    ok=1;
                    break;
                }
            }
            if(ok) break;
        }
        for(int i=lsp+1;i<=a[pos];i++) r+=c[pos];
        for(int i=pos+1;i<=n;i++){
            for(int j=1;j<=a[i];j++) r+=c[i];
        }
    }else{
        ll sm=0,lsp=0;
        for(int i=1;i<=pos;i++){
            bool ok=0;
            for(int j=1;j<=a[i];j++){
                l+=c[i];
                sm++;
                if(sm==mid){
                    lsp=j;
                    ok=1;
                    break;
                }
            }
            if(ok) break;
        }
        for(int i=lsp+1;i<=a[pos];i++) r+=c[pos];
        for(int i=pos+1;i<=n;i++){
            for(int j=1;j<=a[i];j++) r+=c[i];
        }
    }
    // cout<<l<<' '<<r<<'\n';
    ll ans=0,len=l.size();
    reverse(r.begin(),r.end());
    for(int i=0;i<len;i++) ans+=l[i]!=r[i];
    cout<<ans<<'\n';
    return 0;
}