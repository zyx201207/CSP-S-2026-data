#include<bits/stdc++.h>
using namespace std;
const int N=1e7+5000;
int a[N];
char c[N];
long long sum;
string s;
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        for(int j=1;j<=a[i];j++)
        {
            s=s+c[i];
        }
    }
    sum=s.size();
    long long cnt=0;
    if(sum%2==1) sum=(sum-1)/2;
    else sum/=2;
    for(int i=1;i<=sum;i++)
    {
        if(s[i]!=s[1+s.size()-i])
        {
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
