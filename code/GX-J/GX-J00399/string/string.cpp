#include<bits/stdc++.h>
using namespace std;
long long a[200007];
char c[100000009],b[200007];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin.tie(0);
    ios::sync_with_stdio(false);
    long long f,t=0,n,i,sum=0,sun,j,ans=0;
    cin>>n;
    for(i=0;i<n;i++)
        {
        cin>>a[i]>>b[i];
        sum+=a[i];
        }
    /*for(i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl<<b;*/
    for(i=0;i<n;i++)
        for(j=1;j<=a[i];j++)
    {
        c[t]=b[i];
        t++;
    }
  //  cout<<c;
    for(i=0,j=t-1;i<=j;i++,j--)
        if(c[i]!=c[j])ans++;
    cout<<ans;
    return 0;
}
