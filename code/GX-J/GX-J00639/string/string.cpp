#include <iostream>
using namespace std;
int a[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string .out","w",stdout);
    ios::sync_with_stdio(false);
    int sum=0;
    long long n;
    string s="";
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        long long k;
        string a;
        cin>>k>>a;
        for (int i=1;i<=k;i++)
        {
            s+=a;
        }
    }
    for (int i=1;i<=n;i++)
    {
        if (s[i]!=s[n+1-i])
            sum++;
    }
    cout<<sum;
    return 0;
}
