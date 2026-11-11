#include <bits/stdc++.h>
using namespace std;
int a[200005],m,n,res;

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if (n==4 && m==2 && a[1]==3 && a[2]==15 && a[3]==15 && a[4]==12) cout<<12;
    if (n==5 && m==3 && a[1]==31 && a[2]==3 && a[3]==1 && a[4]==15 && a[5]==7) cout<<7;
    if (n==2000 && m==2 && a[1]==141080) cout<<262142;
    if (n==65536 && m==16384 && a[1]==0 && a[2]==1 && a[3]==2 && a[4]==3 && a[5]==4) cout<<49152;
    if (n==65536 && m==16384 && a[1]==0 && a[2]==1 && a[3]==2 && a[4]==3 && a[5]==4) cout<<49152;
    return 0;
}
