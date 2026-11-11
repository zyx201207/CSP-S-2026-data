#include<bits/stdc++.h>

using namespace std;

const int N=2e6+5;

int n,flag;
long long x[N],,d,c,t,ans=0,ways=0,vis[N];

void dfs(long long place,int leng,long long e,int num);
{
    if(place==e)
    {
        if(flag>leng)
        {
            ways=0;
            flag=leng;
            return;
        }
        if(flag==leng)
        {
            ways++;
            return;
        }
        if(flag<leng)
        {
            return;
        }
    }
    for(int i=place;i<=num;i++){
        if(x[i]-x[place]<=d)
        {
            dfs(i,leng+1,e,num);
        }
    }
}

int main(void)
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    cin>>c>>t;

    while(t--)
    {
        cin>>n>>d;
        memset(x,0,x.size());
        ans=0,ways=0;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                flag=INT_MAX;
                dfs(x[i],0,x[j],j);
                if(ways==2)
                {
                    ans++;
                }
                ways=0;
            }
        }
        cout<<ans<<endl;
    }

}
