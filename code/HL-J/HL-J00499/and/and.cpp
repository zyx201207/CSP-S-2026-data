#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[200009];

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << noboolalpha;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<a[n-1];
    return 0;
}
