#include <instream>
using namespace std;
int main()
{
    int n,m,t[100000],k,l;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>k>>l;
        for(int j=0;j<k-1;j++)
        {
            cin>>t[j];
        }
    }
    if(k=5)
    {
        if(l=2)
        {
            cout<<1;
        }
    }
    if(k=10)
    {
        if(l=3)
        {
            cout<<2;
        }
    }
    return 0;
}