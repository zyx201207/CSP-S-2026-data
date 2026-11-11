#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fo(i,j,k) for(register int i=j;i<=k;i++)
const int N=2e5;
int n,m,x,y,k,cnt,ans,a[N],s[N];
char c[N];
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    fo(i,1,n) {cin>>a[i]>>c[i];s[i]=s[i-1]+a[i];};
    int i=1,j=n;
    while(i<j)
    {
        char cur=c[i],cur2=c[j];
        k=min(a[i],a[j]);
        //cout<<k<<" "<<i<<" "<<j<<endl;
        if(cur!=cur2) ans+=k;
        a[j]-=k,a[i]-=k;
        if(a[j]==0) j--;
        else i++;
    }
    cout<<ans;
    return 0;
}
