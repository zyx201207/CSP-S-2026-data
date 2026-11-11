#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int x[n];string b[n],s;
    for(int i=0;i<n;i++)
    {
        cin>>x[i]>>b[i];
        for(int j=0;j<x[i];j++)
        {
            s+=b[i];
        }
    }
    string h;
    for(int i=s.size();i>=0;i--)
    {
        h+=s[i];
    }
    if(s==h)cout<<0;
    return 0;
}
