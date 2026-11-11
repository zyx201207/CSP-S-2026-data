#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string a[105];
    int s=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    string s=a[i];
    for(int i=0;i<n;i++)
    {
        s=s%10;
        s=s/10;
        s=s*10+s;
        if(s=n)
        {
            cout<<s;
        }
    }
return 0;
}
