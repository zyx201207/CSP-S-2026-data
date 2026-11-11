#include<bits/stdc++.h>
using namespace std;
long long n,l,cnt,ans;
char a[100000008],c;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d %c",&l,&c);
        for(int i=1;i<=l;i++) a[++cnt]=c;
    }
    for(int i=1;i<=cnt/2;i++)
    {
        if(a[i]!=a[cnt-i+1]) ans++;
    }
    cout<<ans;
    return 0;
}
