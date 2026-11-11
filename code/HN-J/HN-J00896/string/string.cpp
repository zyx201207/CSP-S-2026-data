#include <bits/stdc++.h>

using namespace std;
char s[1299999999];
int n,o;
struct v{
    int a;
    char c;
}v[250000];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>v[i].a>>v[i].c;
        o+=v[i].a;
    }
    if(v[1].c==v[n-1].c)
        cout<<0;
    else
        cout<<o/2;
    return 0;
}
