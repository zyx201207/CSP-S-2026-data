#include<bits/stdc++.h>
using namespace std;
long long a;
char c;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n=0,sum=0;
    cin>>n;
    string s;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>c;
        for(int i=0;i<a;i++)s.push_back(c);
    }
    for(int i=1;i<=s.size()/2;i++)
    {
        int j=s.size()+1-i;
        if(s[i]!=s[j])
        {
            sum++;
        }
    }
    cout<<sum;
    return 0;
}
