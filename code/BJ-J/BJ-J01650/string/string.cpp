#include <bits/stdc++.h>
using namespace std;
const int N=2e5+7;
int a[N],cnt;
char c[N];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    string s="";
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        for(int j=1;j<=a[i];j++)
        {
            s+=c[i];
        }
    }
    int len=s.size();
    for(int i=0;i<len;i++)
    {
        if(s[i]!=s[len-i-1]) cnt++;
    }
    cout<<cnt/2;
    return 0;
}
