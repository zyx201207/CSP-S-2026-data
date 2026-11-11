#include<bits/stdc++.h>
using namespace std;
long long cha[500010],qzh_cha[500010];
long long a[500010];
long long n,m;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin>>n>>m;
    for(int i = 1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i = 2;i<=n;i++)
    {
        cha[i]=cha[i-1]+abs(a[i]-a[i-1]);
    }
    for(int i = 2;i<=n;i++)
    {
        qzh_cha[i]=qzh_cha[i-1]+cha[i];

    }
    for(int i = n;i>=1;i--)
    {
        if(((i-1)*cha[i]-qzh_cha[i-1])<=m)
        {
            cout<<i;
            return 0;
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
