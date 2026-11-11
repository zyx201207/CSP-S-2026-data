#include <bits/stdc++.h>
using namespace std;
string s,t;
long long ans,sum;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        int m;
        cin >> m >> t;
        sum+=m;
        for(int j=1;j<=m;j++)
            s+=t;
    }
    int l=0,r=sum-1;
    while(l<r)
    {
        if(s[l]!=s[r])
            ans++;
        l+=1,r-=1;
    }
    cout << ans;
    return 0;
}
