#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n, m;
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1, a+1+n);
    int num=a[1];
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=num)
        {
            cout<<a[i];
            return 0;
        }
    }
    return 0;
}
