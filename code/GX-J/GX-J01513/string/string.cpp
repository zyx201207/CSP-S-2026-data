#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,tj=0;
    cin>>n;
    int sa[n];
    char sc[n];
    for(int i=0;i<n;i++)
    {
        cin>>sa[i]>>sc[i];
    }
    int l=0,r=n-1;
    while(l<r)
    {
        if(sc[l]!=sc[r])
        {
            tj++;
        }
        sa[l]-=1;
        sa[r]-=1;
        if(sa[l]==0)
        {
            l+=1;
        }
        if(sa[r]==0)
        {
            r-=1;
        }
    }
    cout<<tj;
}
