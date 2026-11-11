#include<iostream>;
using namespace std;

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int m=0;
    int n=0;
    int a[100000]={0};
    int ans[100000]={0};
    int z[100000]={0};
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n,i++)
    {
        for(int j=i-1;j<n;j++)
        {
            for(int p=i-1;p<j;p++)
            {
                if(z[p]==a[j])
                {
                    for(int s=p;s<j;s++)
                    {
                        z[s]=-1;
                    }
                }
            }
          z[j]=a[j];
        }
        for(int j=0;i<n;j++)
        {
            if(z[j]!=-1)
            {
                ans[z[j]]+=1;
            }
        }
    }
    for(int i=0;i<m;i++)
    {
        cout<<ans[i]<<' ';
    }
        return 0;
}
