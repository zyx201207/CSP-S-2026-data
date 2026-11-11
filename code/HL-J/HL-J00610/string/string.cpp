#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N],ans,b;
char c[N],d[N];
string s;

int main()
{
    //freopen("string.in","r",stdin);
    //freopen("string.out","w",stdin);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i]>>c[i];
        ans+=a[i];
    }

    cout<<ans/2;
     return 0;
}
