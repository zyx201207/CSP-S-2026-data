#include<bits/stdc++.h>
using namespace std;
const int MAXN=200000+2;
int n,m,a[MAXN],x,b[MAXN],bl,ans=0;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int wei=30;wei>=0;wei--){
        for(int i=1;i<=n;i++){
            if(a[i]&(1<<wei)){
                b[++bl]=a[i];
            }
        }
        if(bl>=m){
            for(long long i=1;i<=bl;i++)
                a[i]=b[i];
            n=bl;
            ans+=(1<<wei);
        }
        bl=0;
    }
    cout<<ans<<endl;
}
