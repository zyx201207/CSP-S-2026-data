#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,sum=0;
    string z,zz;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int num;
        cin>>num;
        sum+=num;
        char zimu;
        cin>>zimu;
        for(int j=1;j<=num;j++)
            z+=zimu;

    }
    bool aa=true;
    for(int m=1;m<=sum;m++)
        for(int k=sum;k>=1;k--)
        {
            if(z[m]!=z[k])
            {aa=false;
            break;}
        }
    if(aa==1)cout<<0;
    else cout<<2;
    return 0;

}
