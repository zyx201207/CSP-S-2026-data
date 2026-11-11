#include <iostream>
#include<bits/stdc++.h>
long long int w[100000];
long long int a[1000][1000];
long long int t[1000][1000];
bool visd[10000];
long long int ans=INT_MAX;
bool visl[10000];
using namespace std;
long long int k;
long long int c,n,m,d,q;
void dfs(long long int x,long long int y,long long int res=0)
{
    if(x==y)
    {
        ans=std::min(res,ans);
        return;
    }
    else{
        for(int i=1;i<=n;i++)
            if(a[i][x]&&!visl[i]){
                visl[k]=1;
                for(int j=1;j<=m;j++)
                    if(a[i][j]&&!visd[j]){
                        visd[j]=1;
                        dfs(j,y,res+t[i][x]+t[i][j]);
                        visd[j]=0;
                    }
                visl[k]=0;
            }

    }
}
int main()
{
    freopen("subway.out","w",stdout);
    freopen("subway.in","r",stdin);
    std::cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    std::cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&k);
        for(int j=1;j<=k;j++){
            long long int ca,ct;
            std::cin>>ca>>ct;
            a[i][ca]=1;
            t[i][ca]=ct;
        }
    }
    while(q--)
    {
        int x,y;
        std::cin>>x>>y;
        dfs(x,y,w[x]+w[y]);
        std::cout<<ans<<'\n';
        ans=INT_MAX;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
