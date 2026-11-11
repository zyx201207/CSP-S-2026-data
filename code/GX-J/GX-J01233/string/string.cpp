#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    int n;
    cin>>n;
    string s;
    for(int i=0;i<n;i++)
    {
        int a;
        string b;
        cin>>a>>b;
        for(int j=0;j<a;j++)
        {
            s+=b;
        }
    }
    string s2;
    for(int i=s.size()-1,j=0;i>=0,j<s.size();i--,j++)
    {
        s2[j]=s[i];
    }
    int m=s.size()/2;
    int sum=0;
    for(int i=0;i<m;i++)
    {
        if(s[i]!=s2[i])
        {
            sum++;
        }
    }
    cout<<sum;
    return 0;
}
