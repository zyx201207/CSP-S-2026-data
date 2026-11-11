#include <bits/stdc++.h>
using namespace std;
const int N=1e5*2+10;
struct Str
{
    int cnt;
    char c;
}a[N];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int mx=0;
    long long len=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].cnt>>a[i].c;
        mx=max(mx,a[i].cnt);
        len+=a[i].cnt;
    }
    long long cnt=0;
    if(mx<=510)
    {
        string s="";
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=a[i].cnt;j++)
            {
                s+=a[i].c;
            }
        }
        for(int i=0;i<len/2;i++)
        {
            if(s[i]!=s[len-1-i])
            {
                cnt++;
            }
        }
    }
    else
    {
        long long sum=0;
        int id_k=1;
        for(int i=1;i<=n;i++)
        {
            if(sum<len/2&&sum+a[i].cnt>=len/2)
            {
                id_k=i;
                break;
            }
            sum+=a[i].cnt;
        }

    }
    cout<<cnt;
    return 0;
}
