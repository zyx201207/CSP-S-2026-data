#include <iostream>
int a[100000000];
int maxis=0;
int n,m;
int maxand()
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i]&a[j]>maxis)
            {
                maxis=a[i]&a[j];
            }
        }
    }
    return maxis;
}
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<maxand(n,m);
    return 0;
}
