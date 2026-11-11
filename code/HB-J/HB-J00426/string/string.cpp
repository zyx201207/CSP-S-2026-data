#include<bits/stdc++.h>
using namespace std;
long long a[200020];
char c[200020];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    long long sum=0,c1=0;
    cin>>n;
    string s="";
    bool f=1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        sum+=a[i];
    }
    for(int i=1;i<=n;i++)
    {
        if(i>1 && c[i]!=c[i-1])
            f=0;
        if(!(a[i]==a[n-i+1] && c[i]==c[n-i+1] && n%2 && i!=n/2+1))
        {
            for(int j=0;j<a[i];j++)
                s+=c[i];
        }
    }
    if(f)
    {
        cout<<0;
        return 0;
    }
    for(long long i=0;i<s.size()/2;i++)
    {
        if(s[i]!=s[s.size()-i-1])
            c1+=1;
    }
    cout<<c1;
    return 0;
}
