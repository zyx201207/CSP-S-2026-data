#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    long long a[n+10];
    int s[n+10][8];
    long long max=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        s[i][1]=a[i]%2;
        s[i][2]=a[i]/2%2;
        s[i][3]=a[i]/4%2;
        s[i][4]=a[i]/8%2;
        s[i][5]=a[i]/16%2;
        s[i][6]=a[i]/32%2;
        s[i][7]=a[i]/64%2;
        s[i][8]=a[i]/128%2;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=n+1;j>=1;j--)
        {
            long long ans=(s[i][1]^s[j][1])*1+(s[i][2]^s[j][2])*2+(s[i][3]^s[j][3])*4+(s[i][4]^s[j][4])*8+(s[i][5]^s[j][5])*16+(s[i][6]^s[j][6])*32+(s[i][7]^s[j][7])*64+(s[i][8]^s[j][8])*128;
            if(ans>max)
            {
                max=ans;
            }
        }
    }
    cout<<max;
    return 0;
}
