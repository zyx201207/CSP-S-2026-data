#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,i;
    string a;
    cin>>n;
    long long m[n],j;
    char c[n+2];
    for(i=0;i<n;i++)
    {
        cin>>m[i]>>c[i];
        for(j=0;j<m[i];j++) a+=c[i];
    }
    j=a.length();
    n=0;
    for(i=0;i*2+1<j;i++)
    {
        if(a[i]!=a[j-1-i]) n++;
        else
        {
            i+=min(m[i],m[j-i-1])-1;
        }
    }
    cout<<n;
    return 0;
}
