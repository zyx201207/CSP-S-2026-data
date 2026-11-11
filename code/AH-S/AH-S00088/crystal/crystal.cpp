#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long a[N],b[N];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,maxn=1;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        b[i]=b[i-1]+a[i];
    for(int i=2,j=1;i<=n;i++)
    {
        while(a[i]*(i-j+1)-(b[i]-b[j-1])>m&&i>=j) j++;
        if(maxn<i-j+1) maxn=i-j+1;
    }
    cout<<maxn;
    return 0;
}
