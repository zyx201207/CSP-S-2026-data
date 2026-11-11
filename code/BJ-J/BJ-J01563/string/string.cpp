#include<bits/stdc++.h>
using namespace std;
int a[200005];
int b[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    long long sum=0,ans=0;
    for(int i=1;i<=n;i++)
    {
        char an;
        int bn;
        cin>>bn>>an;
        a[i]=an-'a';
        b[i]=bn;
        sum+=b[i];
    }
    long long l=1,r=sum,pos1=1,pos2=n;
    while(l<=r&&pos1<=pos2)
    {
        long long len=min(b[pos1],b[pos2]);
        if(a[pos1]!=a[pos2])
        {
            ans+=len;
        }
        b[pos1]-=len;
        b[pos2]-=len;
        if(b[pos1]==0) pos1++;
        if(b[pos2]==0) pos2--;
        l=l+len;
        r=r-len;
    }
    cout<<ans;
    return 0;
}