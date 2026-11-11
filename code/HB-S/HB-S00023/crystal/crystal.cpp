#include<bits/stdc++.h>
using namespace std;
const int N=5e5+100;
long long a[N],s[N];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    long long m;
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for (int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    int num=0;
    for (int i=1;i<=n;i++)
    {
        int l=1,r=i-1,ans=-1;
        while (l<=r)
        {
            int mi=(l+r)/2;
            if (a[i]*(i-mi)-(s[i-1]-s[mi-1])<=m) r=mi-1,ans=mi;
            else l=mi+1;
        }
        if (ans!=-1) num=max(num,i-ans+1);
    }
    cout<<num;
    return 0;
}
