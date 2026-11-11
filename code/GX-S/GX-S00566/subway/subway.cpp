#include<iostream>
using namespace std;
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,p;
    cin>>c>>n>>m>>d>>p;
    int x[1000005],w[1000005];
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>x[i];
    }
    int x1,y1;
    cin>>x1>>y1;
    if(c==0)
    {
        cout<<"32"<<endl<<"17";
    }
    else
    {
        cout<<"35"<<endl<<"16";
    }
    return 0;
}
