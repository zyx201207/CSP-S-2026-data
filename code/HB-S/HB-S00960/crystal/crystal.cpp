#include<bits/stdc++.h>
using namespace std;
const int N=5e5+4;
int n;
long long m;
long long a[N],pri[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    int k;
    bool ok=true;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i==2)k=a[i]-a[i-1];
        else if(i>2 && a[i]-a[i-1]!=k)ok=false;
    }
    if(ok){
        for(int i=1;;i++){
            if((i+1)*i/2*k==m){
                cout<<min(i+1,n);
                return 0;
            }
            if((i+1)*i/2*k>m) {
                cout<<min(i,n);
                return 0;
            }
        }
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        pri[i]=pri[i-1]+a[i];
    }
    int ans=1;
    int l=0,r,len;
    for(int i=2;i<=n;i++){
        r=i;
        while(l<=r){
            if(l==0)len=r-l;
            else len=r-l+1;
            if(pri[r]-pri[l]+m<len*a[i]){
                if(l==r){
                    len=0;
                    break;
                }
                l++;
            }
            else break;
        }
        ans=max(len,ans);
    }
    cout<<ans;
    return 0;
}
