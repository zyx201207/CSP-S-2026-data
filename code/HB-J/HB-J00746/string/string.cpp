#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long a,sum=0,num=0;
    int n;
    string k,b;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b;
        num+=a;
        for(int j=1;j<=a;j++)
        {
            k+=b;
        }
    }
    for(int i=0;i<num;i++)
    {
        if(k[i]!=k[num-i-1])
        {
            sum++;
        }
    }
    cout<<sum/2;
    return 0;
}
