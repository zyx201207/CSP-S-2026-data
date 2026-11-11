//GZ-J00268 冉晋贤 遵义市第五十五中学 
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000000],c=0,sum=0;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]>a[i+1])
        {
            int b;
            b=a[i+1];
            a[i+1]=a[i];
            a[i]=b;
        }
    }
    for(int i=n;i>=m;i--)
    {
        sum=a[i]|a[i-1];
    }
    cout<<sum;
    return 0;
}
