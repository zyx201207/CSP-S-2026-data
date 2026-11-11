#include<bits/stdc++.h>
using namespace std;
long long n,a,ans=0;
string s,c;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(long long i=1;i<=n;i++)
    {
        cin >> a >> c;
        while(a--)
        {
            s+=c;
        }
    }
    for(long long i=0;i<s.size();i++)
    {
        if(s[i]!=s[s.size()-i-1])
        {
            ans++;
            s[s.size()-i-1]=s[i];
        }
    }
    cout << ans;
    return 0;
    }
