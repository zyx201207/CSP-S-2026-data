#include<bits/stdc++.h>
using namespace std;

int a[200005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int f=1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=i-1)
        {
            f=0;
            break;
        }
    }
    if(f) cout<<n-m;
    else{
        sort(a+1,a+n+1);
        cout<<a[m];
    }
    return 0;

}
