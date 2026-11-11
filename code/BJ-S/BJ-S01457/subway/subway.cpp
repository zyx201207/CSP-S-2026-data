#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        cout<<(n-d/(a[2]-a[1])-1)*(d/(a[2]-a[1])-1)-(n-d/(a[2]-a[1])-2)*(n-d/(a[2]-a[1])-2)/2<<endl;
    }
    return 0;
}
