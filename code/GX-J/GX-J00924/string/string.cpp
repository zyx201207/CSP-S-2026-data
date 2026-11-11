#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ant,sum=1;
char s[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i]>>s[i];
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(s[i]==s[j])
                sum+=1;
        }
    }
    cout<<s;
    if(sum==n)
    {
        cout<<0;
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]%2==0)
            ant+=a[i]/2;
        else
        {
            for(int j=i+1;j<n;j++)
            {
                if(s[i]==s[j])
                    if(s[j]%2!=0)
                       ant+=(a[i]+a[j])/2;
            }
        }

    }
    cout<<ant;
    return 0;
}
