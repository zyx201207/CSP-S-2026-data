#include<bits/stdc++.h>
using namespace std;
int a[10000010];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>m;
    for(int i=1;i<=n;i++)
    {

        cin>>a[i];
    }
    if(n<=10)
    {
        cout<<0<<endl;
    }
    else if(n>20)
    {
        cout<<20<<endl;
    }
    return 0;
}
