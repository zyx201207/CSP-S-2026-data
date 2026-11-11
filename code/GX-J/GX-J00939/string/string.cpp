#include<bits/stdc++.h>
using namespace std;
long long a[2000005];
char b[2000005];
bool hw(string a)
{
    for(int i=0;i<=a.size()/2;i++)
    {
        if(a[i]!=a[a.size()-i])
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,l=0,sl=0;
    string s;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
        for(int j=1;j<=a[i];j++)
        {
            s[l]=b[i];
            l++;
        }
    }
    while(1)
    {
        if(hw(s))
        {
            cout<<sl;
            return 0;
        }
        else
        {
            for(int j=0;j<=s.size()/2;j++)
            {
                if(s[j]!=s[s.size()-j])
                {
                    s[s.size()-j-1]=s[j];
                }
            }
            sl++;
        }
    }
    return 0;
}
