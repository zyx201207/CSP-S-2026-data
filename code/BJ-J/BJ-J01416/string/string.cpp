#include<bits/stdc++.h>
using namespace std;
char c[200008];
int a[200008];
char s[10000008];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int m=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        for(int j=1;j<=a[i];j++)
        {
            s[++m]=c[i];
        }
    }
    int ans=0;
    for(int i=1;i<=m/2;i++)
    {
        if(s[i]!=s[m-i+1])ans++;
    }
    cout<<ans;
}