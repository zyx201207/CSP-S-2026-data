#include <bits/stdc++.h>
using namespace std;


int m=0;
int n=0;
int a[500000]={0};
int b=0;
int ans=0;
int last=1;
int main()
{
   freopen("crystal.in","r",stdin);
   freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        if(i!=0)
        {
            b=m;
            last=1;
            for(int j=i-1;j>=0;j--)
            {
                if(b>=a[i]-a[j])
                {
                    b=b-(a[i]-a[j]);
                    last++;
                }
            }


            ans=max(ans,last);
        }
    }
    cout<<ans;
    return 0;
}
