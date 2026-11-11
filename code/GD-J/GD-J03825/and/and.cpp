#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[200005],cnt[200005];
struct node
{
    int c[200005];
    int p;
    int step;
}maxs[25];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(m==1)
    {
        cout<<a[n];
        return 0;
    }
    for(int i=1;i<=20;i++)
    {
        maxs[i]={{},0,0};
    }
    for(int i=1;i<=n-1;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if((a[i]&a[j]) >=maxs[1].p)
                {
                    maxs[1].p= (a[i]&a[j]);
                    maxs[1].c[1]=i;
                    maxs[1].c[2]=j;
                }
        }
    }
    if(m==2)
    {
        cout<<maxs[1].p;
        return 0;
    }
    //cout<<maxs[1].c[1]<<' '<<maxs[1].c[2]<<endl;
    for(int i=2;i<=m-1;i++)
    {
        for(int j=1;j<=n;j++)
        {

            if((a[j] & maxs[i-1].p) >=maxs[i].p )
            {
                bool flag=1;
                for(int k=1;k<=i;k++)
                {
                    if(maxs[i-1].c[k]==j&&maxs[i-1].c[k]!=j-1)
                    {
                        flag=0;
                        break;
                    }
                }
                if(flag)
                {

                    maxs[i]=maxs[i-1];
                    maxs[i].p= (maxs[i-1].p & a[j]);
                    maxs[i].c[i+1]=j;
                }
            }

        }

    }
    /*for(int i=1;i<=m;i++)
    {
        cout<<maxs[i].p<<' '<<maxs[i].c[1]<<' '<<maxs[i].c[2]<<endl;
    }*/
    cout<<maxs[m-1].p;
    return 0;
}
