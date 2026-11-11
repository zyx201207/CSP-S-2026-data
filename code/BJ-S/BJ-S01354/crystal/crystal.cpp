#include<bits/stdc++.h>
using namespace std;
const int maxn=5009;
int n,ans=0,res;
int a[maxn],w,m;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    /*
    for(int i=1;i<=n;i++){
        cout<<a[i];
    }
    */
    if(n<=5000){
        for(int i=1;i<=n;i++){
            res=1,w=m;
            for(int j=i-1;j>0;j--){
                if(w<1) break;
                if(a[i]-a[j]<=w){
                    res++;
                    w-=(a[i]-a[j]);
                }
            }
            ans=max(ans,res);
        }
        cout<<ans<<'\n';
        return 0;
    }
    return 0;
}
