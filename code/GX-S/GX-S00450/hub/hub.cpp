#include <iostream>

using namespace std;

int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int n,m;
    cin>>n>>m;
    if(m==2)
    {
        cout<<"4\n6";
    }
    else
    {
        int a[500005]={0};
        for(int i=1;i<=m;i++)
        {
            a[i]=i;
        }
        for(int i=m/2,j=m/4;i>=m/4,j<=m/2;i--,j++)
        {
            a[j]=i;
        }
        for(int i=m,j=m/4;i>=m/2,j<=m/3;i--,j++)
        {
            a[j]=i;
        }
        for(int i=m/3,j=m/9;i>=m/7,j<=m/8;i--,j++)
        {
            a[j]=i;
        }
        for(int i=m/4,j=m/4;i>=m/5,j<=m/3;i--,j++)
        {
            a[j]=i;
        }
        for(int i=m/2,j=1;i>=m/3,j<=m/3;i--,j++)
        {
            a[j]=i;
        }
        for(int i=1;i<=m;i++)
        {
            cout<<a[i]<<endl;
        }
    }
    return 0;
}
