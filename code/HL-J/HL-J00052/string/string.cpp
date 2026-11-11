#include<bits/stdc++.h>
using namespace std;
long long n,a,sum,m;
char c;
string s="";
int main()
{
    //freopen("string.in", "r", stdin);
    //freopen("string.out", "w", stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>c;
        for(int j=1;j<=a;j++)
            s+=c;
    }
    m=s.length();
    for(int i=0;i<m/2;i++)
    {
        if(s[i]!=s[m-i-1])
        {
            sum++;
        }
    }
    cout<<sum;
    return 0;
}
