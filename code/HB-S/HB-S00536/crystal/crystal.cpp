#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD=500010;
int a[MOD];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m,f=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i>=3&&a[i]-a[i-1]!=a[i-1]-a[i-2]) f=1;
    }
    if(f==0){
        int k=max(a[n]-a[n-1],a[n-1]-a[n]),cn;
        for(int i=1;i<=n;i++){
            int r=(i+1)*i/2;
            if(r>m){
                cn=i-1;
                break;
            }
            else if(r==m){
                cn=i;
                break;
            }
        }
        cout<<min(n,cn);
        return 0;
    }
    sort(a+1,a+n);
    int c=m,res=1;
    int r=1,l=1;
    while(1){
         r++;
         c=c-(a[r]-a[r-1])*res;
         if(c<0) break;
         res++;
    }
    int k=res;
    c+=(a[r]-a[r-1])*res;
    if(c<0){
        while(l<=r&&r<=n){
            if(c<(a[r]-a[r-1])*(k-1)){
                c=c+(a[r]-a[l]);
                l++;
                k--;
                continue;
            }
            else{
                c=c-(a[r]-a[r-1])*k;
                r++;
                k++;
            }
            res=max(k,res);
        }
    }
    cout<<res;
    return 0;
}
