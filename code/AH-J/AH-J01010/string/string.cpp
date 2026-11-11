#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+7;
int a[N];
char c[N],d[N];
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,ans=1,sum=0,f=1,num=0,g=0;
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i] >> c[i];
        if(i > 1&&c[i]!=c[i-1])
        {
            ans=0;
        }
        sum+=a[i];
        g=f+a[i]-1;
        for(int j = f;j <= g;j++)
        {
           d[j]=c[i];
        }
        f=g+1;
    }
    if(ans==1)cout << 0;
    else
    {
        int p=sum/2;
        int l = 1,r = sum;
        while(l <= p&&r>=sum-p+1)
        {
            if(d[l]!=d[r])num++;
            l++;
            r--;
        }
    }
    cout << num;
    return 0;
}

