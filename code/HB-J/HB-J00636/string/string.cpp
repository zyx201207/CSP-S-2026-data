#include<bits/stdc++.h>
using namespace std;
int a[200005];
char b[200005];
long long c[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    long long all=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
        all+=a[i];
        c[i]=c[i-1]+a[i];
    }
    //mid=(all+1)/2;
    //int midi=n;
    //for(int i=1;i<n;i++)
    //{
       //if(c[i]<=mid&&c[i+1]>=mid)
       //{
          // midi=i;
        //   break;
      // }
    //}
    long long l=1,r=all;
    int li=1,ri=n;
    long long ans=0;
    while(l<r)
    {
        if(c[li]-l+1<=r-c[ri-1])
        {
            ans+=(c[li]-l+1)*(b[li]!=b[ri]);
            r-=c[li]-l+1;
            li++;
            l=c[li-1]+1;
        }
        else
        {
            ans+=(r-c[ri-1])*(b[li]!=b[ri]);
            l+=r-c[ri-1];
            ri--;
            r=c[ri];
        }
    }
    cout<<ans;

    return 0;
}
