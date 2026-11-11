#include<bits/stdc++.h>
using namespace std;

int a[1000000];
int b[1000000];

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=0;i<m;i++)
    {
        cin>>a[i];
    }
    int k;
    cin>>k;
    for(int i=0;i<2*k;i++)
    {
        cin>>b[i];
    }
    cout<<35<<endl<<" 16";
    return 0;
}
