#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s,s1,b;
    long long n,a,sum=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        cin>>b;
        for(int j=1;j<=a;j++)
            s+=b;
    }
    long long m=s.size();
    s1=s.substr(0,ceil(m/2));
    reverse(s1.end(),s1.begin());
    string s2;
    s2=s.substr(ceil(m/2),m);
    for(int i=0;i<min(s1.size(),s2.size());i++)
    {
        if(s1[i]!=s2[i])
            sum++;
    }
    cout<<sum;
    return 0;
}
