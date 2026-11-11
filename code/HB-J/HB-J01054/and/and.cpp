#include <bits/stdc++.h>
using namespace std;
int a[200005];
bool cmp(int a,int b)
{
    if(a!=b) return a>b;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,reply;
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];
    sort(a+1,a+n+1,cmp);
    reply=a[1];
    for(int i=2;i<=m;i++)
    {
        int temp=reply&a[i];
        reply=temp;
        cout << temp << ' ';
    }
    for(int i=1;i<=n;i++) cout << a[i] << ' ';
    cout << reply;
    return 0;
}
