#include <bits/stdc++.h>
using namespace std;
int n;
int t;
int ans;
string w;
string a="";
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>t>>w;
        for(int j=1;j<=t;j++)
        {
            a+=w;
        }
    }


    int tl=a.length();
    int l=tl/2+tl%2;

    for(int i=0;i<l;i++){
        if(a[i]!=a[tl-i-1])
        {
            ans++;
        }
    }

    cout<<ans;

    return 0;
}
