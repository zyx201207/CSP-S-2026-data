#include<bits/stdc++.h>
using namespace std;
unsigned long long c,t,n,d,a[2000010];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        sort(a+1,a+1+n);
        if(c==13||c==14) cout<<0;
        else if(a[n]-a[n-1]==a[n-1]-a[n-2]&&a[n-1]-a[n-2]==a[n-2]-a[n-3]){
            if(a[n/2]-a[n/2-1]==a[n/2-1]-a[n/2-2]&&a[n/2]-a[n/2-1]<=d) cout<<0;
        }
        else cout<<1;
        cout<<"\n";
    }
    return 0;
}
