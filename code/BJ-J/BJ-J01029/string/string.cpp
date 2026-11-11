#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
using namespace std;

int n;
const int MAXN=2e5+10;
int a[MAXN];
char c[MAXN];
long long L=0;
string s="";

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        L+=a[i];
        for(int j=1;j<=a[i];j++) s+=c[i];
    }

    int ans=0;
    for(int i=1,j=L;i<=L/2;i++,j--)
    {
        if(s[i-1]!=s[j-1]) ans++;
    }

    cout<<ans;

    return 0;
}
