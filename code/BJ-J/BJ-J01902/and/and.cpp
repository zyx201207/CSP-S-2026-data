#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[200005];
bool splitted[200005][35];
void split(int a,int put)
{
    int len=0;
    while(a)
    {
        splitted[put][len++]=a&1;
        a>>=1;
    }
}
int ok[200005],ok2[200005];
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    int i,j;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        split(a[i],i);
    }
    int cnt=0;
    for(i=1;i<=n;i++)
    {
        ok[i]=i;
    }
    int len=n,lenn=0;
    int ans=0;
    for(i=31;i>=0;i--)
    {
        cnt=0;
        lenn=0;
        for(j=1;j<=len;j++)
        {
            if(splitted[ok[j]][i])
            {
                cnt++;
                ok2[++lenn]=ok[j];
            }
        }
        if(cnt>=m)
        {
            ans+=pow(2,i);
            memset(ok,0,sizeof(ok));
            for(j=1;j<=lenn;j++)
            {
                ok[j]=ok2[j];
            }
            len=lenn;
            memset(ok2,0,sizeof(ok2));
        }
        else
        {
            memset(ok2,0,sizeof(ok2));
        }
    }
    cout<<ans;
    return 0;
}
