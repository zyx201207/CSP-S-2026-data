#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int m,n,sum=0,cnt=0,l,r;
    char mp[100000010];
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> m;
        for(int j=1;j<=m;j++)
        {
            cin >> mp[sum+j];
        }
        sum=sum+m;
    }
    if(sum%2==0)
    {
        l==sum/2;
        r=l+1;
        while(l!=0)
        {
            if(mp[l]!=mp[r])
            {
                cnt++;
            }
            l--;
            r++;
        }
    }
    if(sum%2==1)
    {
        l=sum/2;
        r=l+2;
        while(l!=0)
        {
            if(mp[l]!=mp[r])
            {
                cnt++;
            }
            l--;
            r++;
        }
    }
    cout << cnt;
    return 0;
}
