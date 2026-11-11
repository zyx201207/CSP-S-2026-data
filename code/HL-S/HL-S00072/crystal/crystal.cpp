#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[100001],sum[100001],s[100001];
ll n ,m,ans;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(ll i=1;i<=m;i++){
        sum[i]=a[i]-a[i-1];
        s[i]=s[i-1]+sum[i]*i;
    }
    for( ans =1;ans<=n;ans++){
        if(s[ans]<=m){
            m-=s[ans];
        }
        else{
            break;
        }
    }
    cout<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
