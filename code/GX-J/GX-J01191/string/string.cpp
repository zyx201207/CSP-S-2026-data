#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s,s1=" ",s2=" ";
    int n,a,sum=0,b;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>s;
        for(int j=1;j<=a;j++)
        {
            s1+=s;
        }
    }
    if(s1.size()%2!=0)
    {
        b=s1.size()/2+1;
    }
    else
    {
        b=s1.size()/2;
    }
    for(int i=0;i<=b;i++)
    {
        for(int j=s1.size();j>=b;j++)
        {
            if(s1[i]!=s1[j])
            {
                sum++;
            }
        }
    }
    cout<<sum;
    return 0;
}
