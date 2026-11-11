#include<bits/stdc++.h>
using namespace std;
int n;
long long cnt;
string s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a;
        char c;
        cin>>a>>c;
        s.insert(s.size(),a,c);
    }
    long long len=s.size();
    for(int i=0;i<(len+1)/2;i++)
    {
        if(s[i]!=s[len-i-1]) cnt++;
    }
    cout<<cnt;
    return 0;
}
