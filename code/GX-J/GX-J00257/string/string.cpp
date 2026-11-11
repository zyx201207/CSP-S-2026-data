#include<bits/stdc++.h>
using namespace std;
long long n,a[200010],cnt=0,nr;
char c[200010];
string s="";
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
    }
    for(int i=1;i<n;i++)
    {
        if(a[i]==a[n])
        {
            cnt+=(c[i]!=c[n])*a[i];
            n--;
        }
        else if(a[i]>a[n])
        {
            cnt+=(c[i]!=c[n])*a[n];
            a[i]-=a[n];
            i--;
        }
        else
        {
            cnt+=(c[i]!=c[n])*a[i];
            a[n]-=a[i];
        }
    }
    cout<<cnt;
    return 0;
}
