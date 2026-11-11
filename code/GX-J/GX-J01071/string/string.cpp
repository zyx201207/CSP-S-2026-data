#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200001];
char b[200001];
int c=0,l=0;
int main()
{
    string s;
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
        l+=a[i];
    }
    if(n==1)
    {
        cout<<0;
        return 0;
    }
    if(n==2)
    {
        if(b[1]!=b[2])
        {
            cout<<min(a[1],a[2]-a[1]);
        }
        else
        {
            cout<<0;
        }
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=a[i];j++)
        {
            s+=b[i];
        }
    }
    for(int i=0;i<s.size()/2;i++)
    {
        if(s[i]!=s[s.size()-i+1])
        {
            c++;
        }
    }
    cout<<c;
    return 0;
}
