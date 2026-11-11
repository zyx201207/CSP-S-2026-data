#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long a[N];
char c[N];
long long n,l;
long long num;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
    }
    for(int i=1;a[i+1]!=0||a[i-1]!=0;)
    {
        if(c[i]!=c[n+1-i])
        {
            num+=min(a[i],a[n+1-i]);

        }
        if(a[i]>a[n+1-i])a[i]-=a[n+1-i],a[n+1-i]=0,n--;
        else a[n+1-i]-=a[i],i=n+1-i,a[n+1-i]=0,n--;
        if(a[i]==0&&i>n/2)i--;
        else if(a[i]==0&&i<n/2)i++;
    }
    cout<<num;
    return 0;
}
