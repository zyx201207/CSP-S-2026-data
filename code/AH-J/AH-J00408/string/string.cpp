#include<bits/stdc++.h>
using namespace std;
int n,qwe[200010];
char wer[200010];
string s;
long long ans,sum;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        string ert;
        cin>>qwe[i]>>ert;
        sum+=qwe[i];
        for(int j=1;j<=qwe[i];j++)
        {
            s=s+ert;
        }
    }
    for(int i=0;i<sum/2;i++)
    {
        if(s[i]!=s[sum-1-i])
        {
            ans++;
        }
    }
    cout<<ans;
}
