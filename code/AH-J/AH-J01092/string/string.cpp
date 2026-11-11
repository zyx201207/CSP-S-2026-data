#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,m[1000005],ans,t,sum;
    string s,s1;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>m[i]>>s;
        sum=sum+m[i];
        s1=s1+s;
    }
    t=1;
    for(int i=0;i<=n/2;)
    {
        if(m[i]!=0)
        {
            if(s1[i]==s1[n-t])
            {
                if(m[i]>m[n-t])
                {
                    m[n-t]=0;
                    t++;
                }
                else
                {
                    m[i]=0;
                    i++;
                }
            }
            else
            {
                if(m[i]>m[n-t])
                {
                    ans=ans+m[n-t];
                    m[n-t]=0;
                    t++;
                }
                else
                {
                    ans=ans+m[i];
                    m[i]=0;
                    i++;
                }
            }
        }
    }
    if(sum%2==0 || ans==0)cout<<ans;
    else cout<<ans-1;
    return 0;
}
