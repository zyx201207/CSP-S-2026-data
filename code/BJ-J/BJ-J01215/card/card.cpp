#include<iostream>
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    long long n,m,a[1000005],s,k=0,ss=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        s=i,k=0;
        for(int j=i+1;j<=n;j++)
        {
            if(a[i]==a[j])
            k=j;
        }
        if(k==0)
        {
            a[n+1]=a[i];
            n++;
        }
        a[i]=0;
        else{
            for(int j=k+1;j<=n;j++)
                a[j]=0;
            n=k;
        }
    }
    for(int i=1;i<=m;i++)
    {
        ss=0;
        for(int j=1;j<=n;j++)
        {

            if(a[j]==i)ss++;
        }
        cout<<ss<<" ";
    }
    freopen("card.out","w",stdout);
    return 0;
}
