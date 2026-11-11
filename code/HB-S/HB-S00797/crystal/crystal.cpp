#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int x,n,m,a[1000000],ans=0;
    cin>>n>>m;
    if(m<0){
      return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int j=m;j>=1;j--){
        for(x=j-1;x>=1;x--){
                if(((a[j]-a[x])+(a[j]-a[x-1]))==m){
                    if((n+a[x-1])>=ans){
                        if(n+a[x]<=n-a[x]){
                            ans=(n+a[x]);
                    }else{
                        ans=(n-a[x]);
                    }
                }
                break;
                }
            }
        }
    cout<<ans;
    return 0;
}
