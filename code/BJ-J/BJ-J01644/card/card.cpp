#include<iostream>
#include<algorithm>
using namespace std;

int a[500005],box[300005];

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        box[a[i]]=i;
    }
    for(int i=1;i<=m;i++)
    {
        cout<<box[i]<<" ";
    }
    return 0;
}
