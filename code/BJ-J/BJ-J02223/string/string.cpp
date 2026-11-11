#include<bits/stdc++.h>
using namespace std;
char cs[1000000005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int ma=0;
    for(int i=0;i<n;i++)
    {
        int m;
        cin>>m;
        char c;
        cin>>c;
        for(int j=0;j<m;j++)
        {
            cs[ma]=c;
            ma++;
        }
    }
    ma--;
    if(ma%2!=0)ma--;
    int ans=0;
    for(int i=0;i<ma/2;i++)
    {
        if(cs[i]!=cs[ma-i-1])
        {
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
