#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    int n;
    ll m;
    cin>>n>>m;
    int a[500005];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    ll d[500005];
    int s[500005];
    d[0]=0;
    d[1]=a[1];
    s[0]=0;
    s[1]=a[1];
    bool sp=1;
    for(int i=2;i<=n;i++){
        d[i]=a[i]-a[i-1];
        if(i>=3 && d[i]!=d[i-1]) sp=0;
        s[i]=s[i-1]+a[i];
    }

    //d[n+1]=-INT_MAX;
    if(sp){
        int l=1,r=n;
        int ans=-1;
        while(l<=r){
            int mid=(l+r)/2;
            ll cnt=mid*(mid+1)/2*d[2];
            if(cnt<=m){
                ans=max(ans,mid);
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        cout<<min(n,ans+1);
    }
    else{
        int answer=-1;
        for(int i=1;i<=n;i++){
            ll cnt=0;
            int ans=0;
            for(int j=i;j>=1 && cnt+a[i]-a[j]<=m;j--){
                cnt+=a[i]-a[j];
                ans++;
            }
            answer=max(answer,ans);
        }cout<<min(n,max(1,answer));
    }
    return 0;
}
