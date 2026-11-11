#include<bits/stdc++.h>
using namespace std;
unsigned long long a[10000000];
char s[1000000];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    unsigned long long sum=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>s[i];
        sum+=a[i];
        a[i]=a[i-1]+a[i];
    }
    unsigned long long ans=0;
    for(unsigned long long i=1;i<=sum/2;i++)
    {
        unsigned long long count=1;
        while(1)
        {
            if(i>a[count-1]&&i<=a[count])
                break;
            else count++;
        }
        char k=s[count];
        count=1;
        while(1)
        {
            if(sum+1-i>a[count-1]&&sum+1-i<=a[count])
                break;
            else count++;
        }
            char m=s[count];
            if(k==m)
                continue;
            else ans++;
    }
    cout<<ans;
    return 0;
}
