#include<bits/stdc++.h>
using namespace std;
int i,j,k,n,m,p;
long long a[500005],tot,x,y,ans,b,c;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(j=2;j<=n;j++)
    {
        tot=0;y=1;
        for(k=j-1;k>=1;k--)
        {
            x=a[j]-a[k];
            if(tot+x<=m)
            {
                tot+=x;
                y++;
            }
            else break;
        }
        if(y>ans)ans=y;
    }
    cout<<ans;
    return 0;
    fclose(stdout);
}
