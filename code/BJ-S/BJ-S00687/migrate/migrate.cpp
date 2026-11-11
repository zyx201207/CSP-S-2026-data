#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,cnt[2000010],cha[2000010],a[2000010],ans;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            int ji=0;
            for(int j=i;j<=n;j++){
                ji++;
                cha[ji]=a[j]-a[i];
            }
            for(int l=1;l<=ji;l++){
                if(cha[l]==(d+d-1)){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
        ans=0;
    }
    return 0;
}
