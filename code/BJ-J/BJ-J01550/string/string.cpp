#include<bits/stdc++.h>
using namespace std;
long long n,ans,a[200005];
char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    for(long long l=1,r=n;l<r;l++){
        while(a[l]>0){
            // cout<<a[l]<<"-"<<c[l]<<" "<<a[r]<<"-"<<c[r];
            if(c[l]!=c[r]){
                ans+=min(a[l],a[r]);
                // cout<<" +"<<min(a[l],a[r]);
            }
            // cout<<endl;
            int num=max(0ll,min(a[l],a[r]));
            a[l]-=num;
            a[r]-=num;
            if(a[r]<=0){
                r--;
            }
        }
        // cout<<endl;
    }
    cout<<ans<<endl;
    return 0;
}
