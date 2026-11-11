#include<bits/stdc++.h>
using namespace std;
long long n,a[10000005],sum=0;
char c[30];
string s,cnt1,cnt2,ans;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i]>>c[i];
        ans+=a[i]*c[i];
    }
    for(int i=0;i<ans.size();i++)
    {
        s+=ans[i];
    }
    if(s.size()%2==0)
    {
        for(int i=0;i<s.size()/2;i++)
        {
            cnt1+=s[i];
        }
        for(int i=s.size()/2;i<s.size();i++)
        {
            cnt2+=s[i];
        }
        for(int i=0;i<s.size()/2;i++)
        {
            long long x=s.size();
            if(cnt1[i]!=cnt2[x])
            {
                sum++;
            }
            x--;
        }
    }
    if(s.size()%2==1)
    {
        for(int i=0;i<s.size()/2;i++)
        {
            cnt1+=s[i];
        }
        for(int i=s.size()/2;i<s.size();i++)
        {
            cnt2+=s[i];
        }
        long long x=s.size();
        for(int i=0;i<s.size()/2+1;i++)
        {
            if(cnt1[i]!=cnt2[x])
            {
                sum++;
                
            }
            x--;
        }
        
    }
    cout<<sum;
    return 0;
}

