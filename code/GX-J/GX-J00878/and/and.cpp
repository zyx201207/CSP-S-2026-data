#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200005],i;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    int s=a[1];
    for(i=2;i<=m;i++)
    {
        s&=a[i];
    }
    cout<<s;
    return 0;
}
