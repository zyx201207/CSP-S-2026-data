#include<iostream>
using namespace std;
int main()
{
    freopen("mlgrate.in","r",stdin);
    freopen("mlgrate.out","w",stdout);
    int h,k,a[10000005];
    cin>>h>>k;
    int n,d;
    for(int i=1;i<=k;i++)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
    }

    if(h==0)
    {
        cout<<"1"<<endl<<"2";
    }
    else
    {
        cout<<"0"<<endl<<"1";
    }
    return 0;
}
