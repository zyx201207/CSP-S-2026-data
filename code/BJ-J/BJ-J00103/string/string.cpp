#include<bits/stdc++.h>
using namespace std;
const int N=2e5+4;
long long sd[N];
char c[N];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,cnt=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>sd[i]>>c[i];
        sd[i]=sd[i-1]+sd[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(long long j=sd[i-1]+1;j<=sd[i];j++)
        {
            if(j>(sd[n]+1)/2) break;
            long long x=sd[n]+1-j;
            int l=1,r=n,id;
            while(l<=r)
            {
                int mid=(l+r)>>1;
                if(sd[mid]>=x)
                {
                    id=mid;
                    r=mid-1;
                }
                else
                {
                    l=mid+1;
                }
            }
            if(c[id]!=c[i]) cnt++;
        }
        if(sd[i]>(sd[n]+1)/2) break;
    }
    cout<<cnt<<"\n";
    return 0;
}