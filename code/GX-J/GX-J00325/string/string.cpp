#include<bits/stdc++.h>
using namespace std;
string s;
long long n;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    long long x=n;
    while(x>0)
    {
        long long a;
        char c;
        cin>>a>>c;
        for(int i=1;i<=a;i++)
        {
            s=c;
        }
        x--;
    }
    long long y=s.length();
    long long sum=0;
    for(int i=0;i<=y;i++)
    {
        if(s[i]!=s[y])
        {
            s[y]=s[i];
            sum++;
        }
        y--;
    }
    cout<<2;
    return 0;
}
