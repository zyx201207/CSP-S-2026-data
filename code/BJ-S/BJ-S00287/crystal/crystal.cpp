#include<iostream>
#include<algorithm>
using namespace std;
long long a[500010],b[500010],n,m,test=0;
int maxn=1;
void f(int z)
{
    if(z==0)
    {
        for(int i = 1; i <= n; i++)
        {
            b[i]=a[i];
        }
        sort(b+1,b+n+1);
        int x=1;
        for(int i = 2; i <= n; i++)
        {
            if(b[i]==b[i-1])x++;
            else{
                maxn=max(maxn,x);
                x=1;
            }
        }
        return;
    }
    for(int i = 1; i <= n; i++)
    {

        a[i]+=1;
        f(z-1);
        a[i]-=1;
    }
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >>m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    f(m);
    cout << maxn;
    return 0;
}