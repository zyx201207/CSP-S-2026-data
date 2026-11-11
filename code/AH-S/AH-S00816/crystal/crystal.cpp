#include <bits/stdc++.h>
using namespace std;
//void gai(int weishu,int a1,int a2,int a3,int a4,int a11,int a22,int a33,int a44)
//{
    //for (int i=1;i<=weishu;i++)
    //{
        //for (int j=1;j<=i;j++)
        //{

        //}
    //}
//}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m,aa[500005],a[500005],b[100],bb[100],bbb[100],shumu=0;
    b[1]=1;
    b[2]=1;
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        cin>>aa[i];
    }
    for (int i=3;i<=m;i++)
    {
        for (int j=1;j<=i-1;j++)
        {
            b[i]+=b[j];
        }
    }
    //for (int i=1;i<=n;i++)
    //{
        //cout<<b[i];
    //}
    //sort(a[1],a[1+n+1]);
    int c=1;
    int zhen=0;
    for(int p=1;p<=m;p++);
    {
        int z=c;
        //int bbb[z+1];
        bb[1]=c;
        bbb[1]=c;
        int u=2;
        for (int k=2;k<=c;k++)
        {
            bb[k]=1;
            bbb[k]=1;
        }
        for (int j=1;j<=b[c];j++)
        {
            for (int q=1;q<=m+1-z;q++)
            {
                for (int v=1;v<=z;v++)
                {
                    aa[1+v-1+q-1]=a[1+v-1+q-1]+bbb[v];
                }
                for (int w=1;w<=n;w++)
                {
                    shumu=0;
                    int e=aa[w];
                    for (int r=1;r<=n;r++)
                    {
                        if (e==aa[r])
                        {
                            shumu++;
                        }
                    }
                    if (zhen<=shumu)
                    {
                        zhen=shumu;
                    }
                }
            }
            //int h=3
            //for (int o=2;o<=z;o++)
            ///{
                //bbb[o]=0;
            //}
            //for (int g=2;g<=h;g++)
            //{
                //bbb[u]=a[]
            //}
        }
        c++;
    }
    cout<<zhen;
    return 0;
}
