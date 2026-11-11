#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >>n;
    if (n==1) cout<<0;
    string s="";
    for (int i=1;i<=n;i++)
    {
        int num;
        char ss;
        cin >> num>>ss;
        for (int j=1;j<=num;j++)
        {
            s+=ss;
        }
    }
    int l=0,r=s.size()-1;
    int ans=0;
    while (l!=r)
    {
        if (s[l]!=s[r]) ans++;
        l++;
        r--;
    }
    cout<<ans;
    return 0;
}
