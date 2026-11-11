#include <bits/stdc++.h>
using namespace std;

struct S
{
    long long a;
    char c;
};
S s[200001];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    long long sum=0,ans=0;
    for(int i=0;i<n;i++)
    {
        cin>>s[i].a>>s[i].c;
        sum+=s[i].a;
    }
    int l=0,r=n-1,l1=0,r1=sum-1,l2=1,r2=1;
    while(l1<r1)
    {
        if(s[l].c!=s[r].c)
        {
            ans++;
        }
        l1++;
        r1--;
        l2++;
        r2++;
        if(l2>s[l].a)
        {
            l++;
            l2=1;
        }
        if(r2>s[r].a)
        {
            r--;
            r2=1;
        }
    }
    cout<<ans;
    return 0;
}
