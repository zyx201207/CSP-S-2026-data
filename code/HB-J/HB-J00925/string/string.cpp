#include <bits/stdc++.h>
using namespace std;
string s;
int n;
long long sum;
long long ans;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i = 1;i <= n;i++)
    {
        int a;
        string c;
        cin>>a>>c;
        for(int j = 1;j <= a;j++)
        {
            s+=c;
        }
        sum+=a;
    }
    int l = 0,r = sum-1;
    while(r>=l)
    {
        if(s[l]!=s[r])ans++;
        l++;
        r--;
    }
    cout<<ans;
    return 0;
}
