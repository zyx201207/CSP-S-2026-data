#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,T,a[N],b[N];
void f(int x,int y,int z){
    int i=x+1;
    while(a[i]-a[x]<=y&&i<=z){
        b[i]++;
        f(i,y,z);
        i++;
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    while(T--){
        int n,k,ans=0;
        cin>>n>>k;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            b[i]=0;
        }
        f(1,k,n);
        for(int i=1;i<=n;i++){
            if(b[i]>2) ans++;
        }
        if(k>=3) cout<<ans-2;
        else cout<<ans<<endl;
    }
}
