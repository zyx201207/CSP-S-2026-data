#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,ans;
long long m,s[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    sort(s+1,s+n+1);
    for(int i=1;i<=n;i++){
        s[i]+=s[i-1];
    }
    for(int i=1;i<=n;i++){
        int l=1,r=i;
        while(l<r){
            int mid=(l+r)/2;
            if(1ll*(i-mid+1)*(s[i]-s[i-1])-(s[i]-s[mid-1])<=m){
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        ans=max(ans,i-l+1);
        //for(l=1;l<=i;l++){
        //  cout<<l<<" "<<i<<"need: "<<1ll*(i-l+1)*(s[i]-s[i-1])<<" "<<(s[i]-s[l-1])<<endl;
        //}
    }
    cout<<ans<<endl;
    return 0;
}
