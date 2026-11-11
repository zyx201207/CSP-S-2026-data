#include<bits/stdc++.h>
using namespace std;
long long a[200005];
long long d[200005];
long long ans=0;
char c[200005];
char c1[200005];
int n;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        d[n-i+1]=a[i];
        c1[n-i+1]=c[i];
    }
    long long cnt=1,cnt2=1;
    while(cnt<=n&&cnt2<=n)
    {
        if(c[cnt]!=c1[cnt2])
        {
            ans=ans+min(a[cnt],d[cnt2]);
        }
        if(a[cnt]<d[cnt2])
        {            
            d[cnt2]-=a[cnt];
            cnt++;
        }
        else if(a[cnt]>d[cnt2])
        {
            a[cnt]-=d[cnt2];
            cnt2++;
        }
        else if(a[cnt]==d[cnt2])
        {
            a[cnt]=d[cnt2]=0;
            cnt++;
            cnt2++;
        }
    }
    cout<<(ans/2)<<endl;
    return 0;
}