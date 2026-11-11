#include<bits/stdc++.h>
using namespace std;
int n,m;
int tmp[500010];
int tmp1[500010];
int t[300010];
int check(int l,int r,int a)
{
        for(int i=l;i<=r;i++)
        {
            if(tmp1[i]==a)
            {
                 return i;
            }
        }
        return -1;
}
int main()
{
   freopen("card.in","r",stdin);
   freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>tmp[i];
    }
    int cnt=0;
    int sum=0;
    int l1=1,r1=n;
    int l2=1,r2=n;
    for(int i=1;i<=n;i++)
    {
    while(l1!=r1)
    {
        int a=tmp[l1];
        l1++;
        int k=check(l2,r2,a);
        if(k!=-1)
        {
            while(r2!=k)
            {
                tmp[++sum]=tmp1[r2];
                r2--;
            }
            tmp[r2]=a;
        }
        else
        {
            tmp[r2++]=a;
        }
    }
    for(int i=l2;i<=r2;i++)
    {
        t[tmp1[i]]++;
    }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<t[i]<<" ";
    }
    return 0;
}

