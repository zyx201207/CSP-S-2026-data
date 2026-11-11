#include<bits/stdc++.h>
using namespace std;


long long n,m,a[500005],pref[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        pref[i]=a[i]+pref[i-1];
    }
    long long sum=0;
    int l=1,r=1;
    int ans=1;
    for(r=1;r<=n;r++){
        sum=a[r]*(r-l+1)-(pref[r]-pref[l-1]);
        while(sum>m){
            l++;
            sum-=a[r]-a[l-1];
        }
        ans=max(ans,r-l+1);
    }

    cout<<ans;
    return 0;
}
