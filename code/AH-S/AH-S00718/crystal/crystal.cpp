#include<bits/stdc++.h>
using namespace std;
int n,ans,p=1;
long long a[500055],b[500055],c[500055],m;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        b[i]=a[i]-a[i-1];
        c[i]=(i-1)*b[i]+c[i-1];
        for(int j=p;j<=i;j++)
        {
            if(c[i]-c[j]<=m)
            {
                p=j;
                ans=max(ans,i-j+1);
                break;
            }
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
