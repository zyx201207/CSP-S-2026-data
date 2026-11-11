#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string3.in","r",stdin);
 //   freopen("string.out","w",stdout);
    long long n,srs,sum=0,jg=0;
    char src;
    string s="";
    cin>>n;
    for(long long i=1;i<=n;i++)
    {
        cin>>srs>>src;
        sum+=srs;
        for(int j=1;j<=srs;j++)
        {
            s+=src;
        }

    }
    for(int i=1;i<=sum-i;i++)
    {
        if(s[i-1]!=s[sum-i])
        {
            jg++;
        }
    }
    cout<<jg;
    fclose(stdin);
//    fclose(stdout);
    return 0;
}
