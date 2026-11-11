#include<bits/stdc++.h>
using namespace std;
long long n;
long long a;
long long num=0;
char c;
string ch="";
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++)
    {
        cin>>a>>c;
        for(long long j=1;j<=a;j++)
        {
            ch+=c;
        }
    }
    long long sum=ch.length();
    if(sum%2==1)
    {
        long long cen=sum/2;
        for(long long i=cen+1;i<=sum-1;i++)
        {
            if(ch[i]!=ch[cen*2-i])
            {
                num++;
            }
        }
    }
    else if(sum%2==0)
    {
        long long cen=sum/2-1;
        for(long long i=cen+1;i<=sum-1;i++)
        {
            if(ch[i]!=ch[cen*2-i])
            {
                num++;
            }
        }
    }
    cout<<num;
    return 0;
}
