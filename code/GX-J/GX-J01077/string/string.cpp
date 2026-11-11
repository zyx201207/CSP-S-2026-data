#include<bits/stdc++.h>
using namespace std;
long long n,m,l=0;
string s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    if(n==1)
    {
        cout<<0;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>m;
        char a;
        cin>>a;
        for(int j=l;j<=l+m;j++)
        {
            s[j]=a;
        }
        l+=m;
    }
}
