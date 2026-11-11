#include<iostream>
using namespace std;
int n,m,a[500005],sum[300005];
int zsrpyh(int k)
{
    int y[300005];
    bool z[300005];
    for(int i=n-1;i>k-1;i++){
        if(!z[a[i]])z[a[i]]=true,y[a[i]]=i;
        else for(int j=i;j<y[a[i]];i++)z[y[a[i]]]=false;
    }
    for(int i=0;i<m;i++){
        if(z[i])sum[i]++,z[i]=false;
    }
}
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=1;i<=m;i++)zsrpyh(i);
    for(int i=0;i<n;i++)cout<<sum[i]<<' ';
    return 0;
}
