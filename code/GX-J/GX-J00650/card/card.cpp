#include <bits/stdc++.h>
using namespace std;
int n,m,a[10],ans1=0,ans2=0,ans3=0,ans4=0,ans5=0;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out"."w",stdout);
    cin >>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin >>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]==a[i]+1)
        {
            for(int j=1;j<=m;j++)
            {
                int ans;
                if(a[i]+1==j)
                {
                    ans==j;
                }
                if(ans==1)
                {
                    ans1++;
                }
                if(ans==2)
                {
                    ans2++;
                }
                if(ans==3)
                {
                    ans3++;
                }
                if(ans==4)
                {
                    ans4++;
                }
                if(ans==5)
                {
                    ans5++;
                }
            }
        }
        else if(a[i]==a[i]+1)
        {
            for(int z=1;z<=m;z++)
            {
                int ans;
                if(a[i]+1==z)
                {
                    ans==z;
                }
                if(ans==1)
                {
                    ans1++;
                }
                if(ans==2)
                {
                    ans2++;
                }
                if(ans==3)
                {
                    ans3++;
                }
                if(ans==4)
                {
                    ans4++;
                }
                if(ans==5)
                {
                    ans5++;
                }
            }
        }
        if(a[i]==a[i]+1)
        {
            for(int k=1;k<=m;k++)
            {
                int ans;
                if(a[i]+1==k)
                {
                    ans==k;
                }
                if(ans==1)
                {
                    ans1++;
                }
                if(ans==2)
                {
                    ans2++;
                }
                if(ans==3)
                {
                    ans3++;
                }
                if(ans==4)
                {
                    ans4++;
                }
                if(ans==5)
                {
                    ans5++;
                }
            }
        }
        if(a[i]==a[i]+1)
        {
            for(int l=1;l<=m;l++)
            {
                int ans;
                if(a[i]+1==l)
                {
                    ans==l;
                }
                if(ans==1)
                {
                    ans1++;
                }
                if(ans==2)
                {
                    ans2++;
                }
                if(ans==3)
                {
                    ans3++;
                }
                if(ans==4)
                {
                    ans4++;
                }
                if(ans==5)
                {
                    ans5++;
                }
            }
        }
        if(a[i]==a[i]+1)
        {
            for(int u=1;u<=m;u++)
            {
                int ans;
                if(a[i]+1==u)
                {
                    ans==u;
                }
                if(ans==1)
                {
                    ans1++;
                }
                if(ans==2)
                {
                    ans2++;
                }
                if(ans==3)
                {
                    ans3++;
                }
                if(ans==4)
                {
                    ans4++;
                }
                if(ans==5)
                {
                    ans5++;
                }
            }
        }
    }
    cout<<ans1<<" "<<ans2<<" "<<ans3<<" "<<ans4<<" "<<ans5<<" ";
    return 0;
}
