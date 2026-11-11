#include<bits/stdc++.h>
using namespace std;
int a[200005];
char s[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>s[i];
    }
    if(n==1) cout<<'0';
    if(n==2)
    {
        if(s[1]==s[2])
        {
            cout<<'0';
        }
        else{
            cout<<min(a[1],a[2]);
        }
    }
    if(n>=3)
    {
        long long sum=0;
        for(int i=1;i<=n;i++)
        {
            sum+=a[i];
        }
        sum/=2;
        cout<<sum;
    }
    return 0;
}
