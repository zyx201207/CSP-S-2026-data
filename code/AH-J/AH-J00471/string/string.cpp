#include<bits/stdc++.h>
using namespace std;
int a[200005];
string s[200005];
string ccf;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        cin>>s[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<a[i];j++)
        {
            ccf+=s[i];
        }
    }
    unsigned long long ans=0;
    for(int i=0;i<(ccf.size()/2);i++)
    {
        if(ccf[i]!=ccf[ccf.size()-i-1])
        {
            ++ans;
        }
    }
    cout<<ans;
    return 0;
}
