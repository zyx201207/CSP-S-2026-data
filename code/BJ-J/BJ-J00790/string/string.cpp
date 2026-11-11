#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k[200005],sum,jl,jw,jll[200005],jlr[200005];
int nl,nr,jlll,jllr,ans,jsw;
char c[200005],jc;
bool fl=1,fla;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    nr=n+1;
    for(int i=1;i<=n;i++){
        cin>>k[i]>>c[i];
        sum+=k[i];
    }
    if(sum==n){
        for(int i=1;i<=n/2;i++){
            if(c[i]!=c[n-i+1]){
                ans++;
            }
        }
        cout<<ans;
        return 0;
    }
    for(int i=1;i<=n;i++){
        jl+=k[i];
        if(sum%2==0&&jl==sum/2){
            fla=1;
            break;
        }
        if(jl>=sum/2+1){
            jw=i;
            jc=c[i];
            break;
        }
    }
    while(jlll+k[nl+1]<=sum/2){
        if(jlll<=jllr){
            nl++;
            jll[nl]=jll[nl-1]+k[nl];
            jlll+=k[nl];
            if(c[nl]!=c[nr]){
                ans+=min(jllr-jll[nl-1],k[nl]);
            }
        }
        while(jllr<jlll&&jllr+k[nr-1]<=sum/2){
            nr--;
            jllr+=k[nr];
            jlr[nr]=jlr[nr+1]+k[nr];
            if(c[nl]!=c[nr]){
                if(jllr>=jlll){
                    ans+=jlll-jlr[nr+1];
                }
                else{
                    ans+=jllr-jlr[nr+1];
                }
            }
        }
    }
    if(fla){
        cout<<ans;
        return 0;
    }
    if(jlll>jllr){
        if(c[nl]!=c[jw]){
            ans+=jll[nl]-jllr;
        }
        for(int i=nl+1;i<jw;i++){
            if(c[i]!=c[jw]){
                ans+=k[i];
            }
        }
    }
    else if(jlll<jllr){
        if(c[nr]!=c[jw]){
            ans+=jlr[nr]-jlll;
        }
        for(int i=nr-1;i>jw;i--){
            if(c[i]!=c[jw]){
                ans+=k[i];
            }
        }
    }
    cout<<ans;
    return 0;
}
