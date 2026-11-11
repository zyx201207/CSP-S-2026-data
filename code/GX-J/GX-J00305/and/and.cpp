#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int a,b;
    cin>>a>>b;
    int c[a+5];
    for(int i=1;i<=a;i++)
    {
        cin>>c[i];
    }
    sort(c,c+a+1,greater<int>());
    cout<<c[b-1];
    return 0;
}
