#include<iostream>
#include<algorithm>
using namespace std;
long long int n,m;
int a[2000005];
int pre[2000005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    pre[0]=0;
    for(int i=1;i<=n;i++)
        pre[i]=pre[i-1]+a[i];
    for(int w=n;w>0;w--)
        for(int i=n;i-w>=0;i--)
        {
            int num=pre[i]-pre[w-i];
            if(m>=a[i]*w-num)
            {
                cout<<w;
                return 0;
            }
        }
    return 0;
}
