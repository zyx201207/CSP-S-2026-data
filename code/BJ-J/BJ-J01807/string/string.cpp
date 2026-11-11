#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string s = "";
    for(int i = 1;i<=n;i++)
    {
        int x;
        char c;
        cin>>x>>c;
        for(int j = 1;j<=x;j++)s+=c;
    }
    long long ans = 0;
    int l = 0,r = s.size()-1;
    while(l<=r)
    {
        if(s[l]!=s[r])ans++;
        l++;
        r--;
    }
    cout<<ans<<endl;
    return 0;
}
