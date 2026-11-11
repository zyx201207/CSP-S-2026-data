#include<bits/stdc++.h>
#include<algorithm>
#define ll long long
using namespace std;
ll c,T,n,d,a[2000005];
bool check(int n,int x){
    int ans=0;
    for(int i=1;i<x-2;i++){
        if(a[n+x]-a[n+i]<=d&&a[n+i]-a[n]<=d)
            ans++;
        if(ans>2)
            return 0;
    }
    if(ans==2)
        return 1;
    return 0;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    while(T--){
        cin>>n>>d;
        ll ans=0,maxn=0,d1=d*2;
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<n;i++)
            for(int j=i+d1;j>i+2&&a[i]-a[j]>maxn;j--)
                if(a[j]-a[i]<=2*d){
                    maxn=max(maxn,a[i]-a[j]);
                    break;
                }
        if(maxn<=2){
            cout<<0<<endl;
            continue;
        }
        for(int i=0;i<=n-maxn+1;i++)
            if(check(i,maxn+i))
                ans++;
        cout<<ans<<endl;
    }
    return 0;
}