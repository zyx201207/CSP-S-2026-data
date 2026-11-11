#include<bits/stdc++.h>
using namespace std;
int a[5000005];
long long c,t,n,d;
bool flag=false;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        long long k=0;
        long long ans=0;
        cin>>n>>d;
        cin>>a[1];
        if(a[1]<=0)k=-a[1]+1;
        for(long long j=2;j<=n;j++){
            cin>>a[j];
            a[j]+=k;
        }
        sort(a,a+1+n);
        for(long long j=1;j<=n;j++){
            if(a[j]>d+1)ans++;
        }
        cout<<ans<<endl;
    }
return 0;
}
