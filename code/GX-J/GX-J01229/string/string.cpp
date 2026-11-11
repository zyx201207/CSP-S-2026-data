#include<bits/stdc++.h>
using namespace std;
int n;
long long l,c=0;
long long a[200000];
string b[200000];
string s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {

        cin>>a[i]>>b[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=a[i];j++)
        {
            s+=b[i];
        }
    }
    l=s.size();
    for(int i=1;i<l/2;i++)
    {
        if(s[i]!=s[l-i]) c++;
    }
    if(l%2!=0) c++;
    cout<<c;
    return 0;

}
