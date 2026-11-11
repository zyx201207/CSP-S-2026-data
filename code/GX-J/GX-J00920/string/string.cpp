#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,z=0;
    string s;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        char y;
        cin>>x>>y;
        for(int j=1;j<=x;j++)
        {
            s+=y;
            z++;
        }
    }
    int h=0;
    for(int i=0;i<=z/2;i++)
    {
        if(s[i]!=s[z-i])h++;
    }
    cout<<h;
    return 0;
}
