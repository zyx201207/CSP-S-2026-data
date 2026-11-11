#include <bits/stdc++.h>
using namespace std;
int c,t;
long long n,d,a[2000005],ans,cs,dk;
void xz(int z,int y,int leg)
{
    int st=z+1;
    if(leg==0 && st==y) ans++;
    while(a[st]-a[z]<=d && st<y)
    {
        xz(st,y,leg--);
        st++;
    }
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int p=1;p<=t;p++)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            a[i]+=1000000000000000000;
        }
        for(int i=1;i<n-2;i++)
        {
            for(int j=i+3;j<=n;j++)
            {
                ans=cs=0;
                if(a[j] - a[i] <= d) continue;
                cs=floor((a[j]-a[i]-0.5)/d)+1;
                xz(i,j,cs);
                if(ans == 2) dk++;
            }
        }
        cout<<dk<<endl;
    }
    return 0;
}

