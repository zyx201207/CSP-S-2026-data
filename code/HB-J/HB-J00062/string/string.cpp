#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    char s[15];
    int num[15];
    string sc;
    int ans=0;
    int flaga=1;
    for(int i=1;i<=n;i++)
    {
        cin>>num[i]>>s[i];
        for(int j=1;j<=num[i];j++)
        {
            sc+=s[i];
        }
    }
    if(n==1)
    {
        cout<<0;
    }
    else
    {
        for(int i=0;i<sc.length()/2;i++)
        {
            if(sc[i]!=sc[sc.length()-i-1])
            {
                ans++;
            }
        }
        cout<<ans;
    }
}
