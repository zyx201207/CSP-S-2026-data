#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    cout<<a[0];
    return 0;
}
