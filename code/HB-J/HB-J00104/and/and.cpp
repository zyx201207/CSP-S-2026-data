#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n[200005];
    int m;
    cin>>m;
    int min=0;
    for(int i=1; i<=200005; i++)
    {
        cin>>n[i];
    }
    for(int i=1; i<=200005; i++)
    {
        if(n[i-1]<=n[i]<=n[i+1]||n[i-1]>=n[i]>=n[i+1])
        {
            min+=n[i];
            cout<<min<<endl;
            break;
        }
        else
        {
            cout<<0;
            break;
        }
    }
    return 0;
}

