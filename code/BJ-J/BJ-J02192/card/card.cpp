#include <bits/stdc++.h>
using namespace std;
int a[500001],b[300001]={0};
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    bool f=1;
    int g=0;
    for(int i=0;i<n;i++)s
    {
        cin>>a[i];
        b[a[i]]++;
    }
    for(int i=1;i<n-1;i++)
    {

        for(int j=0;j<i;j++)
        {
            f=1;
            for(int h=j;h<i;h++)
            {
                for(int k=i;k<n;k++)
                {
                    if(a[h]==a[k])
                    {
                        f=0;
                        //j++;
                    }
                }


            }
            if(f==1)
            {
                b[a[i]]+=1-g;
            }
        }
        //cout<<b[1]<<" "<<b[2]<<" "<<b[3]<<endl;
    }
    //for(int i=1;i<=m;i++)
    //{
    //    b[i]--;
    //}
    b[a[n-1]]=n;
    for(int i=1;i<=m;i++)
    {
        cout<<b[i]<<" ";
    }
    return 0;
}
