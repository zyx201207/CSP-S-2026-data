#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,a;
    char c;
    string s;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a>>c;
        for(int i=1;i<=a;i++)
             s+=c;
    }
    if(reverse(s.begin(),s.end()==s)
    {
        cout<<0;
        return 0;
    }
    string k=reverse(s.begin(),s.end());
    long long sum=0;
    for(int i=n-1;i>=0;i++)
    {
        if(reverse(s.begin(),s.end())==s) break;
        if(s[i]!=k[i])
        {
            s[i]==k[i];
            sum++;
        }
    }
    cout<<sum;
return 0;
