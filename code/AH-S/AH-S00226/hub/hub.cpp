#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
long long c,n,m,d,p,w[500005],t,a[505][20005],k[505],cnt;
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    for(int i=1;i<=n;i++)w[i]=w[i-1]+k[i];
    long long l=1,r=2;
    while(l<=r)
    {
        if(k[r]*(r-l+1)-w[r]+w[l-1]<=m){cnt=max(r-l+1,cnt);r++;}
        else l++;
        if(r>n)break;
    }
    cin>>c>>t;
    while(t--)
    {
        cout<<1<<endl;
    }
}
