#include <bits/stdc++.h>
using namespace std;
int n;
long long num=0;
long long sum=0;
string s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        long long a;
        string c;
        cin>>a>>c;
        for(int i=1;i<=a;i++)
        {
            s+=c;
            num++;
        }
    }
    for(int i=0;i<=(num+1)/2;i++)
    {
        if(s[i]!=s[num-i])
        {
            sum++;
        }
    }
    cout<<sum;
    return 0;
}
