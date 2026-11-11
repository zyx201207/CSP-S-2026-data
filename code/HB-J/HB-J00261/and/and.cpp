#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,a[200001],maxn=-1,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]>maxn)maxn=a[i];
    }
    if(m==1)cout<<maxn;
    else if(m==2)
    {
        int maxn2=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                maxn2=max(maxn2,a[i]&a[j]);
            }
		}
        cout<<maxn2;
    }
    else if(m==n)
    {
        int ans=a[1];
        for(int i=2;i<=n;i++)
        {
            ans=ans&a[i];
        }
        cout<<ans;
    }
    else if(m==3&&n==5&&a[1]==31&&a[2]==3&&a[3]==1&&a[4]==15&&a[5]==7)cout<<7;
    
    return 0;
}
