#include <iostream>

using namespace std;
int n,m;
int a[5005];
int v[3005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    //cout << "Hello world!" << endl;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=n;i>=1;i--)
    {
        v[a[i]]+=1;
        v[a[i]]*=i;
    }
    for(int i=1;i<=m;i++)
    {
        if(v[i]>0)
        {
            cout<<v[i]<<' ';
        }
    }
    return 0;
}
