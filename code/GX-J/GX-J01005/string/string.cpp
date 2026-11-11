#include<bits/stdc++.h>
using namespace std;
long long a[10000005];
char c[10000005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string s,s1;
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        sum+=a[i];
    }
    int g=0;
    while(s.size()==sum)
    {
        g++;
        for(int i=1;i<=a[g];i++)
        {
            sum+=c[g];
        }
    }
    s1=s;
    if(s1==s)
    {
        cout<<"0";
    }
    return 0;
}
