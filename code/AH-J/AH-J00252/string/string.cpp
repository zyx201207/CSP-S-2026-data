#include<bits/stdc++.h>
using namespace std;
#define int long long
int cnt,sum,a,ans,sum1,sum2,sum3,cnt1,cnt2;
char c;
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    int n,len=0;
    cin>>n;
    string s="";
    for(int i=1;i<=n;i++)
    {
        cin>>cnt>>c;
        for(int i=1;i<=cnt;i++)
        {
            s+=c;len++;
        }
    }
    int mid=len/2;
    for(int i=0;i<mid;i++)
    {
        if(s[i]!=s[len-i-1])ans++;
    }
    cout<<ans;
    return 0;
}
