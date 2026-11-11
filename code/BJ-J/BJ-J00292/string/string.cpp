#include<bits/stdc++.h>
using namespace std;
long long a[200001],ans,n;
char c[200001];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
    }
    long long i=1,j=n;
    while(i<j)
    {
        if(c[i]!=c[j])
        {
            ans=ans+min(a[i],a[j]);
        }
        if(a[i]==a[j])
        {
            a[i]=0;
            a[j]=0;
            i++;
            j--;
        }
        else if(a[i]>a[j])
        {
            a[i]-=a[j];
            a[j]=0;
            j--;
        }
        else
        {
            a[j]-=a[i];
            a[i]=0;
            i++;
        }
    }
    cout<<ans;
    return 0;
}
