#include <bits/stdc++.h>
using namespace std;
int n,a[200005],ans;
char s[200005];
string x,y;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>s[i];
        for(int j=1;j<=a[i];j++)
        {
            x+=s[i];
        }
    }
    int z=0,si=x.size();
    if(si%2) z=1;
    for(int i=0;i<si/2+z;i++)
    {
        if(x[i]!=x[si-i-1]) ans++;
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
