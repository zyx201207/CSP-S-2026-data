#include<bits/stdc++.h>
using namespace std;
const int N=5000000000;
long long a[N],n,m,ans=l,s[N],n;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin tie[0];
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    for(long long i=1;i<=n;i++)
    s[i]=a[i]=s[i-1];
    for(long long i=1;i<=n;i++)
        for(long long j=i+1;j<=n;j++)
        if(s[j]-s[i-1=m])/(j-i+1)>=a[j]ans=max(j-i+1,ans)
        cout<<ans<<endl;



    cout<<3;
return 0;
}

