#include <bits/stdc++.h>
using namespace std;
int n,a[20000],s;
char x[20000];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>x[i];
    }
    int m=n/2;
    int l=1,r=n;
    for(int i=1;i<=m;i++)
    {
        if(x[l]!=x[r])
        {
            s++;
        }
        l++;
        r++;
    }
    cout<<s;
    return 0;
}
