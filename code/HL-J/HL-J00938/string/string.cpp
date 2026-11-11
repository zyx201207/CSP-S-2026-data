#include <bits/stdc++.h>
using namespace std;

string s;
long long a[1000000];
char c[1000000];
int n,len=0,slen,nos=0;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i]>>c[i];
        len+=a[i];
        for(int j=0;j<a[i];j++)
        {
            s+=c[i];
        }
    }

    slen=len/2;
    for(int i=0,j=len-1;i<slen;i++,j--)
    {
        if(s[i]!=s[j])nos++;
    }
    cout<<nos;
    return 0;
}
