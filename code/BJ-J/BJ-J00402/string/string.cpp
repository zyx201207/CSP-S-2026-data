#include <bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
long long a[MAXN],p[MAXN];
string s;
int main()
{
    //freopen("string.in","r",stdin);
    //freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    long long sum=0,m=0;
    long long ans=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i]>>s[i];
        sum+=a[i];
        for(long long j=sum;j<=+a[i];j++)
        {
            p[j]=int(s[i]);
        }
    }
    m=sum/2;
    for(int i=0;i<m;i++)
    {
        if(p[i]==p[sum-i])  continue;
        else ans++;
    }
    cout<<ans<<endl;
    return 0;
}