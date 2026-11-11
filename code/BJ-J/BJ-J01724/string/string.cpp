#include<bits/stdc++.h>
using namespace std;
char s[2000000010];
long long n;
long long cnt=1;
long long g=0;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++)
    {
        long long m;
        char c;
        cin>>m>>c;
        for(long long j=cnt;j<=m+cnt-1;j++)
        {
            s[j]=c;
        }
        cnt+=m;
    }
    cnt-=1;
    for(long long i=1;i<=cnt/2;i++)
    {
        if(s[i]!=s[cnt-i+1])
        {
            g+=1;
        }
    }
    cout<<g;
    return 0;
}