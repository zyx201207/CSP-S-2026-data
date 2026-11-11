#include <bits/stdc++.h>
using namespace std;
int n,m,maxx;
long long a[200005];
int b[200005][35],s1[200005];
int df(int ai,int i)
{
    int k=1;
    while (ai>0)
    {
        b[i][k]=ai%2;
        ai/=2;
        k++;
    }
    maxx=max(k,maxx);
    return 0;
}
int dp(int m1,int i)
{


    for (int j=i;j>=1;j++)
    {
        int m2=0;
        int s2[200005];
        for (int k=1;k<=m1;k++)
        {
            if (b[s1[k]][j]==1)
            {
                m2++;
                s2[m2]=k;
            }
        }
        if (m2>m)
        {
            memset(s1,0,sizeof(s1));

            for (int k=1;k<=m2;k++)
            {
                 s1[k]=s2[k];
            }
            dp(m2,j);
        }
        if (m2==m || m2<=m)
        {
            int sum=a[s2[1]]&a[s2[2]];
            for (int o=3;o<=m2;o++)
            {
                sum&=a[s1[i]];
            }
            cout<<sum;
            return 0;
        }
    }
    return 0;

}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        df(a[i],i);
    }
    for (int i=maxx;i>=1;i++)
    {
        int m1=0;
        memset(s1,0,sizeof(s1));
        for (int k=1;k<=n;k++)
        {
            if (b[k][i]==1)
            {
                m1++;
                s1[m1]=k;
            }

        }
        if (m1>m)
        {
           dp(m1,i);
        }
    }







    fclose(stdin);
    fclose(stdout);
    return 0;
}
