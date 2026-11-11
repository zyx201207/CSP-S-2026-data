#include<bits/stdc++.h>
using namespace std;
int n;
string s;

struct node
{
    int t;
    char c;
}a[200005];

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].t>>a[i].c;
        for(int j=1;j<=a[i].t;j++)
            s+=a[i].c;
    }
    int t=s.length()/2,len=s.length(),cnt=0;
    for(int i=0;i<=t;i++)
        if(s[i]!=s[len-i-1])
            cnt++;
    cout<<cnt;
    return 0;
}
