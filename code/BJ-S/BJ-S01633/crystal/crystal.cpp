#include <instream>
using namespace std;
int main()
{
    long long m,n,p;
    long long a[1000000];
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n-1;i++)
    {
        p=a[i+1]-a[1]
        if(p*i+1<=m)
        {
            m=m-p*i+1;
            k++;
        }
    }
    cout<<k;
    return 0;
}