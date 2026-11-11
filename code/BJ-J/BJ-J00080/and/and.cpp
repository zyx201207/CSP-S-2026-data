#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    long long ans=0;
    scanf("%d%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            cout<<a[i]&a[j]<<" ";
            //ans=max((long long)a[i]&a[j],ans);
    //printf("%d\n",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
