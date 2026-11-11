#include<bits/stdc++.h>
using namespace std;
string s[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    string cnt;
    long long da;
    for(int j=1;j<=n;j++)
    {
        long long n1;
        cin>>n1;
        string a;
        cin>>a;
        da=da+n1;
        for(long long i=1;i<=n1;i++)
        {
            s[j]=s[j]+a;
        }
        cnt=cnt+s[j];
    }
    long long b=da/2;
    long long ans=0;
    long long cnt3;
    cnt3=cnt.size();
    long long cnt1=cnt3;
    for(long long i=0;i<cnt3/2;i++)
    {
        if(cnt[i]!=cnt[cnt1])
        {
            ans++;
        }
        cnt1--;
    }
    cout<<ans;
    return 0;
}
