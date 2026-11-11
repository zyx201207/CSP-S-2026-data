#include<bits/stdc++.h>
using namespace std;
struct str
{
    long long a;
    char c;
}s[200001];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i].a>>s[i].c;
    }
    int first=1,last=n;
    long long ans=0;
    while(n>1)
    {
        if(s[first].c==s[last].c)
        {
            if(s[first].a>s[last].a)
            {
                s[first].a-=s[last].a;
                last--;
                n--;
            }
            else if(s[first].a<s[last].a)
            {
                s[last].a-=s[first].a;
                first++;
                n--;
            }
            else
            {
                first++;last--;
                n-=2;
            }
        }
        else
        {
            if(s[first].a>s[last].a)
            {
                ans+=s[last].a;
                s[first].a-=s[last].a;
                last--;
                n--;
            }
            else if(s[first].a<s[last].a)
            {
                ans+=s[first].a;
                s[last].a-=s[first].a;
                first++;
                n--;
            }
            else
            {
                ans+=s[first].a;
                first++;last--;
                n-=2;
            }
        }
    }
    cout<<ans;
    return 0;
}
