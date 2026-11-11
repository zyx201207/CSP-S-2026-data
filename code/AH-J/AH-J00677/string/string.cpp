#include <bits/stdc++.h>
using namespace std;
int a,b[200005];
char c[200005];
string s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>a;
    for(int i=1;i<=a;i++)
        cin>>b[i]>>c[i];
    for(int i=1;i<=a;i++)
        for(int j=1;j<=b[i];j++)
            s+=c[i];
    int cnt=0;
    for(int i=0;i<s.size();i++)
        if(s[i]!=s[s.size()-1-i])
            cnt++;
    if(cnt%2==0)
        cout<<cnt/2;
    else
        cout<<(cnt+1)/2;
    return 0;
}
