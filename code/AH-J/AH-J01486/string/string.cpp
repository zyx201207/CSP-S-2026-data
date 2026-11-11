#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int a[N],b[N];
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 /*   string s;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    cin>>a[i]>>b[i];
    int l=0,r=n;
    int sum=0;
    int x;
    char y;
    while(l<=r)
    {
        if(y==b[r-1])
        {

        }
        else
        {

        }
        if(a[l]==a[r])
        {
            if(b[l]!=b[r])
            sum+=a[l];
        }
        else
        {
            if(a[l]<a[r])
            {
                x=a[r]-a[l];
                y=b[r];
            }
            else
            {
                x=a[l]-a[r];
                y=b[l];
            }
        }
        l++,r--;
    }
    cout<<sum/2;*/
    int n;
    cin>>n;
    string s;
    for(int i=1;i<=n;i++)
    {
        int a;
        char b;
        cin>>a>>b;
        for(int j=1;j<=a;j++) s+=b;
    }
    int l=0,r=s.size()-1;
    cout<<r<<" ";
    int sum=0;
    while(l<=r)
    {
        if(s[l]!=s[r]) sum++;
        l++,r--;
    }
    cout<<sum;
    return 0;
}
