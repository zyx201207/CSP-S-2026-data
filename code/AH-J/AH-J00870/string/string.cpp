#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m=0;
    string a,c,s;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        for(int j=1;j<=a[i];j++)
        {
            s+=c[i];
        }
    }
    for(int i=1;i<=s.length();i++)
    {
        if(s[i]!=s[s.length()-i+1]) m++;
    }
    cout<<m;
    return 0;
}
