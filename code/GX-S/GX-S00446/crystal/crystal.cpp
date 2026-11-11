#include<bits/stdc++.h>
using namespace std;
const int N=5e5+100;
long long n,m,a[N],ans=1,s[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    for(int i=2;i<=n;i++){
            long long r=1,l=i;
        while(r<l){
            long long mid=(r+l)/2;

            if(mid*a[i]-(s[i-1]-s[i-mid-1])>m) l=mid;

            else r=mid+1;

            ans=max(ans,r);
        }
    }
    cout<<ans;
    return 0;
}
