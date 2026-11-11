#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005]={0},ans=-1,xx=0;
bool xz[200005]={0};
void amx(){
    if(xx!=m) return;
    long long cs=0,thm;
    for(long long i=1;i<=n;i++){
        if(xz[i]==true){
            if(cs==0){thm=a[i];cs=1;}
            else{
                thm &= a[i];
            }
        }
    }
    ans=max(ans,thm);
    return;
}
void xuanze(long long ii){
    if(ii>n) {amx();return;}
    xz[ii]=true;xx++;
    xuanze(ii+1);
    xz[ii]=false;xx--;
    xuanze(ii+1);
    return;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++) cin>>a[i];
    xuanze(1);
    cout<<ans;
    return 0;
}
