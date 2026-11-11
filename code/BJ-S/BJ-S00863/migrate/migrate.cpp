#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int a[100005];
int k[100005];
int lim[100005];
int c,t,n,d;
int count1=0;
int ans=0;
void tryfirst(int st,int ed)
{
    int minlen=(ed-st+d-1)/d;
    if(minlen==1)
        return ;
    for(int i=st;i<=ed;i++)
        lim[a[i]/((ed+minlen-1)/minlen)]++;
    int k=1;
    for(int i=1;i<=minlen;i++)
        k*=lim[i];
    if(k==2)
        ans++;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int p=0;p<t;p++)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)\
                tryfirst(i,j);
        cout<<ans<<endl;
    }
    return 0;
}


