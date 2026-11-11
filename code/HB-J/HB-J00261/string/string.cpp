#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s;
    int n,cnt,L=0;
    string t;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&cnt);
        cin>>t;
        for(int j=1;j<=cnt;j++)
        {
            s+=t;
        }
    }
    int ans=0;
    for(int i=0;i<=n/2;i++)
    {
        if(s[0]!=s[L-i-1])ans++;
    }
    cout<<ans;
    return 0;
}
