#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+1;
char s[maxn];
long long n,ans;
int a[maxn];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    int k=0;
    for(int i=1;i<=n;i++)
    {
        int x;
        char c;
        cin >> x >> c;
        s[k]=c;
        a[k]=x;
        k++;
    }
    long long ans=0;
    for(int i=0,j=0;j<k/2;i++)
    {
        if(s[j]!=s[k-i-1])
        {
            if(abs(a[j]-a[k-i-1])==0)
            {
                j++;
                ans+=a[k-i-1];
                s[k-i-1]=s[j];
            }
            else if(a[j]<a[k-i-1])
            {
                ans+=a[j];
                a[k-i-1]-=a[j];
                j++;
                i--;
            }
            else if(a[j]>a[k-i-1])
            {
                ans+=a[k-i-1];
                a[j]=a[j]-a[k-i-1];
            }
        }
        else j++;
    }
    cout << ans;
    return 0;
}
