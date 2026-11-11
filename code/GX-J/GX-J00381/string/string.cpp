#include<bits/stdc++.h>
using namespace std;
int n,a[200005],ans=0;
char c[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;++i)
        cin >> a[i] >> c[i];
    for(int i=1;i<=(n/2)+1;++i)
    {
        int p=n-i+1;
        if(p<=i)    break;
        else if(a[i]==a[p] && c[i]==c[p])   continue;
        else if(a[i]!=a[p] && c[i]==c[p])
            ans+=(max(a[i],a[p])-min(a[i],a[p]));
        else    ans+=max(a[i],a[p]);
    }
    cout << ans;
    return 0;
}
