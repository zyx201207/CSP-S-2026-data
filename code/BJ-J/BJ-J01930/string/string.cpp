#include <bits/stdc++.h>
using namespace std;
string h;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,j=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a;
        char s;
        cin>>a>>s;
        int o=j;
        for(;j<=o+a;j++)
        {
            h[j]=s;
        }
        j--;
    }
    int l=0,r=j-1;
    int num=0;
    while(l<=r)
    {
        if(h[l]!=h[r])
        {
            num++;
        }
        l++;
        r--;
    }
    cout<<num;
    return 0;
}
