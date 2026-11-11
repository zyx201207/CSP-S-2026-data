#include<bits/stdc++.h>
using namespace std;
int n,x,a[130];
char st[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x>>st[i];
        a[st[i]]+=x;
    }
    cout<<a[st[1]]<<endl;
    return 0;
}

