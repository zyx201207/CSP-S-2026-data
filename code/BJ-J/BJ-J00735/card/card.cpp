#include <iostream>
using namespace std;

int n,m;
int a[200010];
int box[300010];

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

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
