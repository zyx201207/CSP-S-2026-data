#include<bits/stdc++.h>
using namespace std;
long long c,t,n,dd,a[2000005];
__int128 k,d,p;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>dd;
        d=dd;
        for(int i=1;i<=n;i++)cin>>a[i];
        sort(a+1,a+n+1);
        long long kk=a[2]-a[1];
        k=kk;
        __int128 p=d/k;
        long long pp=p;
        if(pp<=1)cout<<"0\n";
        else cout<<max(n-(2*pp)+1,0ll)<<endl;
    }
    return 0;
}
//AFO-2026.10.31
//bye
