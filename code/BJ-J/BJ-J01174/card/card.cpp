#include<iostream>
#include<algorithm>
using namespace std;
const int N=5e5+10;
int n,m,a[N],ans[N],box[N];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=k;i<=n;i++)
        {
            if(box[a[i]]==1)
            {
                for(int j=i-1;a[j]!=a[i];j--)
                {
                    box[a[j]]--;
                }
            }
            else
            {
                box[a[i]]++;
            }
        }
        for(int i=1;i<=m;i++)
        {
            if(box[i]==1) ans[i]++;
            box[i]=0;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<' ';
    }
    return 0;
}
