#include <bits/stdc++.h>
using namespace std;
int n;
long long a,cnt;
char c;
string s;
bool str(string s)
{
    int len=s.size();
    for( int i=0;i<=(len-1)/2;i++ )
    {
        if (s[i]!=s[len-1-i])
        return 0;
    }
    return 1;
}
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    if(n==1)
    {
        cout << "0";
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        cin >>a>>c;
        for(int j=1;j<=a;j++)
        {
            s+=c;
        }
    }
    int len=s.size();
    if(str(s))
    {
        cout << "0";
        return 0;
    }
    else
    {
        for( int i=0;i<=(len-1)/2;i++ )
        {
            if (s[i]!=s[len-1-i])
            {
                s[i]=s[len-1-i];
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}