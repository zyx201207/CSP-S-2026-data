#include<bits/stdc++.h>
#include<string>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,m;
    cin>>n;
    string s,z;
    long long chang=0;
    while(n--)
    {
        cin>>m;
        cin>>s;
        while(m--)
        {
            z+=s;
        }
        chang+=m;
    }
    int sum=0;
    for(long long i=0;i<chang;i++)
    {
        if(z[i]!=z[chang-i-1])
        {
            sum++;
        }
    }
    cout<<sum;
    return 0;
}
