#include <bits/stdc++.h>
using namespace std;
int n,h=1,t=0,ct=0,ans=-888;
long long m,a[500005],c[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        c[++t]=a[i];
        ct+=(c[t]-c[t-1])*(t-h);
        while(ct>m){
            ct-=c[t]-c[h];
            h++;
        }
        if(t-h+1>ans)ans=t-h+1;
    }
    cout<<ans;
    return 0;
}
