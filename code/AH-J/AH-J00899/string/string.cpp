#include<bits/stdc++.h>
using namespace std;
int a[200005],b,c;
int main(void)
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>b;
    for(int i=0;i<b;i++)
    {
        char c;
        cin>>a[i]>>c;
        c+=a[i];
    }
    return 0;
}
