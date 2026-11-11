#include<bits/stdc++.h>
using namespace std;
char c[100000005];
long long ans=0,m=1;
int main()
{
freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
    char t;
    int a;
    cin>>a>>t;
    for(int i=0;i<a;i++)
    {
        c[m++]=t;
    }

    }m--;
    for(int i=1;i<m/2+1;i++)
    {
        //cout<<i<<' '<<m-i+1;
    ans+=(c[i]!=c[m-i+1]);
    }
    cout<<ans<<endl;
}
