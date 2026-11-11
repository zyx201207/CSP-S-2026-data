#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;

struct node
{
    long long x;
    char c;
}s[N];

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    long long n;
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        cin>>s[i].x>>s[i].c;
    }

    long long l=1,r=n;
    long long ans=0;
    while(l<=r)
    {
        if(s[l].c!=s[r].c)
        {
            if(s[l].x>s[r].x)
            {
                s[l].x-=s[r].x;
                ans+=s[r].x;
                r--;
                continue;
            }
            if(s[l].x<s[r].x)
            {
                s[r].x-=s[l].x;
                ans+=s[l].x;
                l++;
                continue;
            }
            if(s[l].x==s[r].x)
            {
                ans+=s[l].x;
                l++;
                r--;
                continue;
            }
        }
        else
        {
            if(s[l].c==s[r].c)
            {
                if(s[l].x==s[r].x)
                {
                    l++;
                    r--;
                    continue;
                }
                if(s[l].x>s[r].x)
                {
                    s[l].x-=s[r].x;
                    r--;
                    continue;
                }
                if(s[l].x<s[r].x)
                {
                    s[r].x-=s[l].x;
                    l++;
                    continue;
                }
            }
        }
    }

    cout<<ans;
    return 0;
}
