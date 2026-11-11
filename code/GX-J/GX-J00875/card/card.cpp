#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen ("card.in","r",stdin);
    freopen ("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int arr[1000005];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int b=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==m)
        {
            b++;
        }
    }
    if(n>=5)
    {
        cout<<n<<" "<<b<<" "<<m;
    }
    else
    {
        cout<<m<<" "<<b<<" "<<n;
    }
    return 0;
}

