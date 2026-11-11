#include <bits/stdc++.h>
using namespace std;
char s1[100007],s2[1000007];
long long a1[100007],a2[100007];
int main()
{

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    char s[200007];
    long long n,a[200007],num=0,sum=0;
    cin>>n;
    for (long long i=1;i<=n;i++)
    {
        cin>>a[i]>>s[i];
        num+=a[i];
    }
    long long q=n,p=1,num1=0;
    while (num1<num/2)
    {
        num1+=a[q];
        a2[p]=a[q];
        s2[p]=s[q];
        p++;
        q--;
    }
    q++;
    p--;
    for (long long i=1;i<q;i++)
    {
        s1[i]=s[i];
        a1[i]=a[i];
    }
    s1[q]=s[q];
    a1[q]=(num1-num/2);
    a2[p]=a2[p]+num/2-num1;
    long long pos1=1,pos2=1,m1=0,m2=0,left=0;

    while (1)
    {
        if (m1>=m2)
        {
            left=m1-m2;
            m2+=a2[pos2];
            left=min(left,a2[pos2]);
            pos2++;
        }
        else
        {
            left=m2-m1;
            m1+=a1[pos1];
            left=min(left,a1[pos1]);
            pos1++;
        }
        if (s1[pos1-1]!=s2[pos2-1])
        {
            sum+=left;
        }
        if (m2>=num/2&&m1>=num/2)
        {

            break;
        }
    }
    cout<<sum;


    return 0;
}
