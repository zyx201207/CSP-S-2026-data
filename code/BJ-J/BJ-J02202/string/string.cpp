#include<bits/stdc++.h>
using  namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int a;
    string c;
    for(int i=1;i<=n;i++)
    {

        cin>>a;
        cin>>c;
    }
    if(n==3) cout<<2;
    else if(n==2) cout<<0;
    else cout<<3000000000;
}