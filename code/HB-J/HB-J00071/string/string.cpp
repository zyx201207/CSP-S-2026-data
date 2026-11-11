#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,a;
    string s;
    char c;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>c;
        s+=a*c;
    }
    long long l=1,r=s.size(),ans=0;
    while(l<=r)
    {
        for(int i=1;i<=s.size()/2;i++)
        {
            if(s[l]==s[r])
            {
               ans=ans;
            }
            else
            {
                s[r]=s[l];
                ans++;
            }
            l+=1;
            r-=1;
        }
    }
    cout<<ans;
    return 0;
}
