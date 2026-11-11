#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5,M=35;
int n,m,cnt=0,sum=0,ans=0;
int a[N],s[M];
bool book[N];
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        for(int j=1,k=0;j<=a[i];j*=2,k++)
        {
            if((a[i]|j)==a[i])
            {
                s[k]++;
                cnt=max(cnt,k);
            }
        }
    }
    for(int i=1;i<=n;i++) book[i]=1;
    for(int i=cnt;i>=0;i--)
    {
        if(s[i]>=m)
        {
            sum=0;
            int k=pow(2,i);
            for(int j=1;j<=n;j++)
                if(book[j]&&(a[j]|k)==a[j])
                    sum++;
            if(sum>=m)
            {
                for(int j=1;j<=n;j++)
                    if((a[j]|k)!=a[j])
                        book[j]=0;
            }
        }
    }
    sum=0;
    for(int i=1;i<=n;i++)
    {
        if(sum==m) break;
        if(book[i])
        {
            sum++;
            if(sum==1) ans=a[i];
            else ans=ans&a[i];
        }
    }
    cout<<ans;
    return 0;
}
