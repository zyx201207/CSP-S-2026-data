#include<bits/stdc++.h>
using namespace std;
const int maxn = 2*(1e6+100);
int num[maxn];
int a[maxn][10];
int ans[10];
void to_2(int n,int now)
{
    int i=8;
    while(n!=0)
    {
        a[now][i]=n%2;
        n/=2;
        i--;
    }
}
void to_10()
{
    int sum=0;
    int wei=8;
    for(int i=1;i<=8;i++)
    {
        int sum1=ans[i];
        for(int j=1;j<wei;j++)
        {
            sum1*=2;
        }
        wei--;
        sum+=sum1;
        //cout<<wei<<" "<<sum1<<endl;
    }
    cout<<sum;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and,out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>num[i];
        to_2(num[i],i);
    }
    /*for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=8;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }*/

    int book=0;
    int bei[2006999];
    memset(bei,0,sizeof(bei));
    for(int i=1;i<=8;i++)
    {
        int sum=0;
        for(int j=1;j<=n;j++)
        {
            if(a[j][i]==1)
            {
                sum++;
            }
        }
        //cout<<sum<<" ";
        if(sum>=m)
        {
            ans[i]=1;
            //cout<<"***";
            for(int j=1;j<=n;j++)
            {
                if(a[j][i]!=1)
                {
                    //cout<<i<<"****"<<j<<endl;
                   for(int k=1;k<=8;k++)
                   {
                       a[j][k]=0;
                      // cout<<j<<" "<<k<<endl;
                   }
                }
            }
        }
    }
        /*cout<<"-----------"<<i<<endl;
        for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=8;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }


    cout<<"ans:";
    for(int i=1;i<=8;i++)
    {
        cout<<ans[i]<<" ";
    }*/

    to_10();
    return 0;

}
