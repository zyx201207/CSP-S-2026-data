#include<bits/stdc++.h>
using namespace std;
#define int long long

int n,len[200005];
char c[200005];
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>len[i]>>c[i];
    }
    int l=1,r=n,cnt=0;
    while(l<r)
    {
        if(len[l]<len[r])
        {
            if(c[l]!=c[r])
            {
                cnt+=len[l];
            }
            len[r]-=len[l];
            l++;
        }
        else if(len[l]>len[r])
        {
            if(c[l]!=c[r])
            {
                cnt+=len[r];
            }
            len[l]-=len[r];
            r--;
        }
        else
        {
            if(c[l]!=c[r])
            {
                cnt+=len[l];
            }
            l++;r--;
        }
    }
    cout<<cnt<<endl;
    return 0;
}