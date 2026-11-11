#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,sum=0,k=0;
    string a="",a1="",a2="";
    cin>>n;
    int b;
    char c;
    for(int i=1;i<=n;i++)
    {
        b=0;
        cin>>b>>c;
        for(int i=1;i<=b;i++)
        {
            a=a+c;
        }
    }
    int m=a.size();
    int m1=m/2,m2;
    if(m1+m1!=m)
    {
        m1++;
        k=1;
    }
    for(int i=0;i<m1;i++)
    {
        a1=a1+a[i];
    }
    if(k=1)
    {
        m2=m1;
    }
    else
    {
        m2=m1+1;
    }
    for(int i=m2-1;i<m;i++)
    {
        a2=a2+a[i];
    }
    for(int i=0;i<=m1;i++)
    {
        if(a1[i]!=a2[m1-i-1])
        {
            sum=sum+1;
        }
    }
    cout<<sum;
    return 0;
}
