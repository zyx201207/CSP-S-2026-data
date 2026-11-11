#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[200005]={};
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n,cmp);
    int cnt=a[1]&a[2];
    for(int i=3;i<=m;i++)
    {
        cnt&=a[i];
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
	return 0;
}
