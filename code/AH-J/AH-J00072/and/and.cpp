#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n;
    cin>>n;
    vector<int>a(n);
    int m;
    cin>>m;
    int sum=1;
    int zuida=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];

    }
    for(int i=0;i<n;i++)
    {
        if(a[i]&a[i+1]>zuida)
        {
            zuida=a[i]&a[i+1];
        }
    }
    cout<<zuida;
    return 0;
}
