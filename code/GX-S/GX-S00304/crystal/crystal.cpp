#include<bits/stdc++.h>
using namespace std;
long long n,a[500005],x,m,mm,ii,ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    mm=m;
    x=0;
    ii=n-1;
    for(int i=n;i>=1;i--){
        if(ii==i){
            ii--;
        }
        while(1){
            if(ii==0){
                ans=max(ans,x);
                cout<<ans+1;
                return 0;
            }
            int w=a[i]-a[ii];
            if(w<=mm){
                mm-=w;
                x++;
                ii--;
            }else{
                ans=max(ans,x);
                break;
            }
        }
        mm+=x*(a[i]-a[i-1]);
        if(x>0){
            x--;
        }

    }
    cout<<ans+1;
    return 0;
}
