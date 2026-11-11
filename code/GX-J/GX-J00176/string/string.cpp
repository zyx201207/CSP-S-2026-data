#include<bits/stdc++.h>
using namespace std;
long long n,s=0;
string s1="",s2;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int b=0;b<n;b++)
    {
        long long a;
        string c;
        cin>>a>>c;
        for(int d=0;d<a;d++)
        {
            s1+=c;
        }
    }
    for(int b=s1.size()-1;b>=0;b--)
    {
        s2+=s1[b];
    }
    for(int b=0;b<s1.size();b++)
    {
        if(s1[b]!=s2[b])
        {
            s++;
        }
    }
    cout<<s/2;
    return 0;
}
