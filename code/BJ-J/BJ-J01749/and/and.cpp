#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
int a[N];//save the int
string s[N];//save the binary
bool f[N];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    int maxn=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        maxn=max(maxn,a[i]);
    }
    int len=log2(maxn)+1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=len;j++)
        {
            s[i]=char((a[i]&1)+'0')+s[i];
            a[i]>>=1;
        }
    }
    
    /*for(int i=1;i<=n;i++)
    {
        cout<<s[i]<<endl;
    }*/
    int ans=0;
    for(int j=0;j<len;j++)//erase or not 0->not 1->erase
    {
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(!f[i]&&s[i][j]=='1')
            {
                cnt++;
            }
        }
        if(cnt>=m)
        {
            ans+=(1<<(len-j-1));
            for(int i=1;i<=n;i++)
            {
                if(!f[i]&&s[i][j]=='0') f[i]=1;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
//1st csp! rp++