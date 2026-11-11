#include<bits/stdc++.h>
using namespace std;
int n;
long long a[100010],maxn;
char c[100010];
string s;
int huiwen(string s1)
{
    long long len=s1.size();
    long long cnt=len-1;
    long long ans=0;
    for(int i=0;i<len;i++)
    {
        if(s[i]!=s[cnt]&&cnt>=i)
        {
            ans++;
        }
        cnt--;
    }
    return ans;
}
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>> n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        s+=c[i];
        maxn=max(a[i],maxn);
    }
    cout<<huiwen(s)*maxn;
    return 0;
}
