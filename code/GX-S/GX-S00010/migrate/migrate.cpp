#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t,n;
    long long k;
    cin>>c>>t;
    while(t--){
        long long a[200005],ans=0;
        unordered_map<long long,bool>b;
        cin>>n>>k;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            b[a[i]]=1;
        }
        for(int i=1;i<=n;i++){
            if(b[a[i]+k]&&b[a[i]+k+k-1]&&b[a[i]+k-1])ans++;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
