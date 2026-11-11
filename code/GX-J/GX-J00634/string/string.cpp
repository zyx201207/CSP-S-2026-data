#include<bits/stdc++.h>
using namespace std;
string c1,c2;
long long a,sum=0,num=0;
int cs,n;
char fh,c3[1000000000];
int main()
{

    freopen("string4.in","r",stdin);
    freopen("string4.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>cs>>fh;
        num+=cs;
        for(int j=sum;j<=num-1;j++)
        {
            c3[j]=fh;

        }
        sum+=cs;
    }
    for(int k=1;k<=num-1;k++)
        {
            if(c3[k-1]!=c3[k])
            {
                c3[k]=c3[k-1];
                a++;
            }
        }
   cout <<a;
    return 0;
}
