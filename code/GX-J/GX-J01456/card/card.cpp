#include <iostream>

using namespace std;
int a[10010];
int b[10010];
int q[10010];
void dfs(int y,int j)
{
    for(int i=y; i<=j; i++)
    {
        b[i]=0;
    }
}
void ss(int k,int s)
{
    for(int i=1; i<=k-s;i++)
    {
        b[i]==a[i+s];
    }
}
int main()
{ freopen("card.in","r",stdin);
  freopen("card.out","w",stdout);
    int n;
    int m;
    cin>>n>>m;
    int d=0;
    int p=-1;
    int u=0;
    int r=0;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];

    }
    int e=n;
    for(int z=1; z<=n; z++)
    {
        e=n-z+1;
        ss(e,z-1);
        for(int i=z;i<=n;i++)
        {
            d=0;

            for(int j=1;j<=e;j++)
            {


                if(a[i]==b[j])
                {
                    dfs(j,e);
                    e=j-1;


                    break;
                }

            }


            b[e+1]=a[i];

            e++;
        }

        for(int i=1; i<=m; i++)

        {
            for(int j=1; j<=e; j++)
            {
                if(b[j]==i)
                {
                    q[i]++;
                        break;
                }
            }
        }


    }
    for(int i=1; i<=m; i++)

    {
        cout<<q[i]<<" ";
    }


}
