#include <bits/stdc++.h>
using namespace std;
long long num[5000005];
long long cha[5000005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    int pian1=0,pian2=0,tep=0;
    for(int i=1;i<=n;i++)
    {
        cin>>num[i];
        if(num[i]==i) pian1++;
    }
    sort(num+1,num+1+n);
    for(int i=1;i<=n;i++)
        {
            if(i==2) tep=num[2]-num[1];
            if(i>2)
            {
                if(num[i]-num[i-1]==tep) pian2++;
            }
        }
    if(pian1==n)
    {
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            cnt+=i;
            if(cnt>m)
            {

                cout<<i;
                return 0;
            }
        }
    }
    if(pian2==n-2)
    {
        int cnt=0,sum=1;
        while(1)
        {
            cnt+=tep*sum;
            if(cnt>m)
            {
                cout<<sum<<endl;
                return 0;
            }
            sum++;
        }
    }
    int cnt=0,ans=0,flag=0;
   for(int i=1;i<=n;i++)
   {
       flag=0,cnt=0;
       for(int j=i;j>=1;j--)
       {
           cnt+=num[i]-num[j];
           if(cnt>m) break;
           flag++;
       }
       ans=max(ans,flag);
   }
    cout<<ans<<endl;
    return 0;
}
