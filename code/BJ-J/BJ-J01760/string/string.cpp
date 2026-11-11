#include<bits/stdc++.h>
using namespace std;
long long n,size,a[200005],ans;
char c[200005];
string s;
int main()
{
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    s=s+" ";
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
    }
    long long i=0,j=n+1,sl=0,sr=0;
    while(i<j)
    {
        if(sr>sl)
        {
            i++;
            sl+=a[i];
        }
        else
        {
            j--;
            sr+=a[j];
        }
        if(c[i]!=c[j]&&sl!=0&&sr!=0)
        {
            if(a[i]<a[j])
            {
                ans+=a[i];
                a[j]-=a[i];
            }
            else
            {
                ans+=a[j];
                a[i]-=a[j];
            }
        }
        if(c[i]==c[j]&&sl!=0&&sr!=0)
        {
            if(a[i]<a[j])
            {
                a[j]-=a[i];
            }
            else
            {
                a[i]-=a[j];
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}