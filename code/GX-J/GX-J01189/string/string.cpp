#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s[10000001];
    int n,m[10000001],sum=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin >>m[i];
    }
    getline(cin,s[n]);
    for(int i=0;i<s[i].size();i++)
    {
        if(s[i]!=s[i+1])
        {
            if(m[i]>m[i+1])
            {
                sum+=m[i+1];
            }
            else
                sum+=m[i];
        }
    }
    cout <<sum;
return 0;
}
