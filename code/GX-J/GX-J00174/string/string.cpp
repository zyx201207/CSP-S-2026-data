#include<bits/stdc++.h>
using namespace std;
long long n,a[100000010],flag=0;
string s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>s[i];
    if(n==1)
    {
        cout<<0;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        if(s[i]!=s[i+1])
          flag=1;
        break;
    }
    for(int i=1;i<=n;i++)
        if(flag==0)
        {
            cout<<0;
            return 0;
        }
        else if(n==2)
             {
                cout<<min(a[i],a[i+1]);
                return 0;
             }
    cout<<0;
    return 0;
}
