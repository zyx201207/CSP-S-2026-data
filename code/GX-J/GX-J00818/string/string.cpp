#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string s=0;
    if(n==1)
        cout<<'0';
    for(int i=1;i<=n;i++)
    {
        int a;
        string c;
        cin>>a>>c;
        s+=c;
    }
    return 0;
}
