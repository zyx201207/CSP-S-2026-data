#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
int a[200100];
int b[200100];
char c[200100];
char d[200100];
void f(int i,int j)
{
    if(i>n+1||j>n+1)
    {
        return ;
    }
    if(c[i]!=d[j])
    {
        if(a[i]>b[j])
        {
            ans+=b[j];
            a[i]-=b[j];
            f(i,j+1);
        }
        else if(b[j]>a[i])
        {
            ans+=a[i];
            b[j]-=a[i];
            f(i+1,j);
        }
        else
        {
            ans+=a[i];
            f(i+1,j+1);
        }
    }
    else
    {
        if(a[i]>b[j])
        {
            a[i]-=b[j];
            f(i,j+1);
        }
        else if(a[i]<b[j])
        {
            b[j]-=a[i];
            f(i+1,j);
        }
        else
        {
            f(i+1,j+1);
        }
    }
}
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
    }
    for(int i=n;i>=1;i--)
    {
        b[n+1-i]=a[i];
        d[n+1-i]=c[i];
    }
    f(1,1);
    cout<<ans/2<<endl;
    return 0;
}
