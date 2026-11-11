#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000000],i,j,k,tot,ans;
set<long long>hx;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(k=1;k<=t;k++)
    {
        cin>>n>>d;
        for(i=1;i<=n;i++)
        {
            cin>>x[i];
            hx.insert(x[i]);
        }
        i=1;
        for(i=1;i<=n;i++)
        {
            j=i;
            if(hx.find(x[i]+d)!=hx.end())
            {
                while(x[j]!=x[i]+d)j++;
                if(x[j+1]-x[j]==d-1)
                {
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
        memset(x,0,sizeof(x));
        hx.clear();
        ans=0;
    }
    return 0;
    fclose(stdout);
}
