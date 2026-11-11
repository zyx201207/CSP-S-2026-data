#include<bits/stdc++.h>
using namespace std;
long long sl=0;
string s;
int n;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a;
        char b;
        cin>>a>>b;
        sl+=a;
        for(int j=1;j<=a;j++)
        {
            s+=b;
        }
    }
    long long su=0;
    if(sl%2==0)
    {
        for(int i=0;i<sl/2;i++)
        {
            if(s[i]!=s[sl-i-1])
            {
                su++;
            }
        }
    }
    else
    {
        for(int i=0;i<=sl/2;i++)
        {
            if(s[i]!=s[sl-i-1])
            {
                su++;
            }
        }
    }
    cout<<su;
    return 0;
}
