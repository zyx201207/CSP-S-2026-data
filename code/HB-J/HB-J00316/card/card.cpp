#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int a[maxn];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,sum=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<m;i++)
    {
        int b=rand();
        int x=b%n==0?n:b%n;
        cout<<x<<endl;
    }
    return 0;
}
