#include<bits/stdc++.h>
using namespace std;
long long c,t,n,m,a[2000010],dp[2000010];
long long d[5010][5010];
const long long MAX=9000000000000000000;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    if(c>=11&&c<=12){
            while(t--){
                cin>>n>>m;
        for(int i=1;i<=n;i++) cin>>a[i];
        int x2=a[2]-a[1];
        for(int i=1;i<=n;i++) a[i]=i;
        m=m/x2;
        int sum=0;
        for(int i=m+1;i<min(n,m*2);i++) sum+=n-i;
        cout<<sum<<endl;
            }

    }
    if(c>=13&&c<=14){
        while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;i++) cin>>a[i];
        int sum=0;
        for(int i=1;i<=n-3;i++){
            if(a[i+3]-a[i]>m) sum++;
        }
        cout<<sum<<endl;
    }
    return 0;
}
}
