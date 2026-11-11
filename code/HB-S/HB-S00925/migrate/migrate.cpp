#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
int c,t,n,d,a[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        int ans=0;
        For(i,1,n)cin>>a[i];
        For(i,1,n){
            For(j,i,n){
                if(a[j]-a[i]>d&&(a[j]-a[i])%d!=0)ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
