#include<iostream>
using namespace std;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m,a[500005],num=1;
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        cin >>a[i]
    }
    int t=a[2]-a[1];
    for(int i=1;i<=n;i++)
    {
        if(m>=i*t)
        {
            m-=i*t;
            num++;
        }
    }
    cout << num;
}
