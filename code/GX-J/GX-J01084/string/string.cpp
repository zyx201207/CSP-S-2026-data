#include<bits/sitc++.h>
using namespace std;
long long n;
char s[2000007];
long long  a[2000007],o=0;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>s[i];
    }
    for(int i=1;i<=n;i++)
    {
        if(s[i]==s[i+1])
        {
        o++;
        }
    }
    if(o==n)
    {
     cout<<0;
    }
    return 0;
}
