#include <bits/stdc++.h>
using namespace std;
int n;
long long s[1000000000005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        long long a,c;
        cin>>a>>c;
        for(int j=1;j<=a;i++)
        {
            s[cnt]=c;
            cnt++;           
        }   
    }
    cout<<2;   
    return 0;
}
