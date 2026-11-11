#include<bits/stdc++.h>
using namespace std;
string s;
string d;
long long a,n;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >>a;
    for(int i=1;i<=a;i+=1)
    {
        cin >>n>>d;
        for(int j=1;j<=n;j+=1)
        {
            s[j]=d[0];
        }
    }
    for(int i=a;i>=1;i-=1)
    {
        cout <<s[i];
    }
    return 0;
}
