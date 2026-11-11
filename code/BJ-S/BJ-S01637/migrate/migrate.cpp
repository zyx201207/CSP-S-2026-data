#include <iomanip>
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_std(false);
    cin.tie(nullptr);
    int c,t,n,d,a[10006],k=0,cnt=n,ans[1009];
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        int s=10009;
        cin>>n>>d;
        for(int j=1;j<=n;j++)
        {
            cin>>a[j];
            if(j>1)
            {
                k=a[j]-a[j-1];
            }
            if(k>d)cnt=j-1;
            if(s>cnt)s=cnt;
        }
        if((a[s]-a[1]>=2*d-1)&&s%2==0) ans[i]=1;
        else ans[i]=0;
    }
    for(int i=1;i<=t;i++)
    {
        cout<<ans[i]<<"\n";
    }
    return 0;
}