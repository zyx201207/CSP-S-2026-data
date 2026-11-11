#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],c[500005],l=1,s,ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        while(true){
            if(s+(a[i]-a[i-1])*(i-l)>m){
                s-=(a[i-1]-a[l]);
                l++;
            }
            else{
                break;
            }
        }
        s+=(a[i]-a[i-1])*(i-l);
        ans=max(ans,i-l+1);
    }
    cout<<ans;
    return 0;
}
