#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen ("and.in","r",stdin);
    freopen ("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int arr[25];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<n;i++)
    {
        if(arr[i]%m==0)
        {
            cout<<arr[i];
        }
    }
    return 0;
}
