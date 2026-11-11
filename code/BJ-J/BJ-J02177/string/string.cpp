#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
bool f=1;
char c[N];
string s,s1,s2;
long long a[N],n;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>s1[i];
        for(int j=1;j<=a[i];j++)
        {
            s+=s1;
        }
    }
    s2=s;
    reverse(s.begin(),s.end());
    for(int i=1;i<=n;i++)
    {
        if(s2!=s)
        {
            f=0;
            break;
        }
    }
    if(f==1)
    {
        cout<<0;
    }
    return 0;
}
