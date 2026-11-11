#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m,a[100005]={},b[100005]={},c[100005]={},x=30,ans=0;
    cin>>n>>m;

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n,cmp);
    for(int i=0;i<m;i++)
    {
        x=30;
        int k=1;
        for(int i=1;i<=29;i++)
        {
            k*=2;
        }
        while(a[i]!=0)
        {
            if(a[i]>=k)
            {
                a[i]-=k;
                if(b[x]==1&&i==m-1)
                {
                    b[x]=1;
                    ans+=k;
                }
                else
                {
                    b[x]=1;
                }

            }
            k/=2;
            x--;
        }

    }
    cout<<ans;
    return 0;
    fclose(stdin);
    fclose(stdout);

}
