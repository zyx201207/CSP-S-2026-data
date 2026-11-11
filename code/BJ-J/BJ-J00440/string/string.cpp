#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N],c[N];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s1;
    long long sum=0;
    int temp=0;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        for(int j=1;j<=a[i];j++)
        {
            s1[++temp]=c[i];
        }
        sum+=a[i];
    }
    long long ans=0;
    for(int i=0;i*2<sum;i++)
    {
        if(s1[i]!=s1[sum-i-1])
        {
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
