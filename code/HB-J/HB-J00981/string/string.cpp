#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,a[200005],x=0,ans=0;
    char c[200005];
    cin>>n;
    char s[n*2+5];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=a[i];j++)
        {
            x++;
            s[x]=c[i];
        }
    }
    int b=n;
    for(int i=1;i<=n;i++)
    {
        if(s[i]!=s[b])
        {
            ans++;
        }
        b--;
    }
    cout<<ans;
    return 0;
}
