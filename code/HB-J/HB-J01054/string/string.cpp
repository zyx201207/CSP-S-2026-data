#include <bits/stdc++.h>
using namespace std;
char s[200005];
char num1[10000005],num2[10000005];
long long a[200005],sum[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,cnt=0;
    cin >> n;
    string num1,num2;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i] >> s[i];
        sum[i]=sum[i-1]+a[i];
    }
    for(int i=1;i<=sum[n]/2;i++)
    {
        for(int j=1;j<=a[i];j++) num1[i]=s[i];
    }
    for(int i=sum[n];i>=sum[n]/2+1;i--)
    {
        for(int j=1;j<=a[i];j++) num2[i]=s[i];
    }
    for(int i=0;i<=sum[n]/2;i++)
    {
        if(num1[i]!=num2[i]) cnt++;
    }
    cout << cnt;
    return 0;
}
