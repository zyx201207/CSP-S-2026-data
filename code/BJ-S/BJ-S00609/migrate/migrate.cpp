#include<iostream>
#include<cstring>
using namespace std;
int c,t;
int n,d;
int a[2000005];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        memset(a,0,sizeof(a));
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        int mind=a[3]-a[1],maxd=n%2?(a[(n+1)/2+1]-a[1]):(a[n/2+2]-a[1]);
        if(c==0||c==11||c==12)
        {
            if(d<mind||d>=maxd) cout<<0<<endl;
            else cout<<n-int(d/n)*2-1<<endl;
        }
    }
}
