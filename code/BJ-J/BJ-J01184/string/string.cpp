#include<bits/stdc++.h>
using namespace std;
int n,a[200005],k,ans;
char c[200005];
vector<char>s;
vector<char>s1;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        k+=a[i];
        for(int j=1;j<=a[i];j++)
        {
            s.push_back(c[i]);
        }
    }
    for(int i=n;i>=1;i--)
    {
        for(int j=1;j<=a[i];j++)
        {
            s1.push_back(c[i]);
        }
    }
    for(int i=1;i<=k;i++)
    {
        if(s[i]!=s1[i])ans++;
    }
    if(ans==0)
    {
        cout<<0;
        return 0;
    }
    cout<<(ans+1)/2;
    return 0;
}
