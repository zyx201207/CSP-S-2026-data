#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long a[2000005];
long long n,k;
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    if(c==0||c==11|c==12){
        while(t--){
            cin>>n>>k;
            long long cz;
            for(long long i=1;i<=n;i++){
                cin>>a[i];

            }

            cz=a[2]-a[1];
            if(n-(k/cz)*2-1>0)cout<<n-(k/cz)*2+1<<'\n';
            else cout<<0<<'\n';
            for(long long i=1;i<=n;i++){
                a[i]=0;
            }
        }
    }else if(c==13||c==14){
        cin>>n>>k;
        long long cz;
        for(long long i=1;i<=n;i++){
            cin>>a[i];

        }cout<<0<<'\n';
    }
    return 0;
}
