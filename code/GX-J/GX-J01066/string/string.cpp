#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    long long h=0;
    for(int i=0;i<=n-1;i++)
    {
        int a=0;
        char c;
        cin>>a>>c;
        for(int j=0;j<=a-1;j++)
        {
            s[h]=c;
            h++;
        }
    }
    //for(int i=0;i<=s.size()-1;i++) cout<<s[i];
    long long t=0;
    for(int i=0;i<=h/2-1;i++)
    {
        if(s[i]!=s[h-1-i])
        {
            t++;
            //cout<<i<<" "<<s.size()-1-i<<" ";
        }
    }
    cout<<t;
    return 0;
}
