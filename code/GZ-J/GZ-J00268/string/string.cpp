//GZ-J00268 冉晋贤 遵义市第五十五中学 
#include<bits/stdc++.h>
using namespace std;
long long n,a[1000000],sum=0;
string s,b[100000];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
        cin>>s[i];
    }
    for(long long i=1;i<=n/2;i++)
    {
        if(n%2==1)
        {
            if(s[i]!=s[n+1-i]&&i!=n+1-i)
            {
                sum+=a[i];
            }
        }
        else
        {
            if(s[i]!=s[n+1-i])
            {
                sum+=a[i];
            }
        }
    }
    cout<<sum;
    return 0;
}
