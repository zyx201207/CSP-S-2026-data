#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int long long n,a[200001],m,ans;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1,cmp);
    cout<<a[m];
    fclose(stdin);
    fclose(stdout);
    return 0;
}
