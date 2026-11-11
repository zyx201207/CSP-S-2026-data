#include <bits/stdc++.h>
using namespace std;

int n, a[505], cnt, b1, b2;
char c[505];
int main()
{
    freopen("travel1.in",'r',stdin);
    freopen("travel.out",'w',stdout);
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i] >> c[i];
    while(1+b1<=n-b2)
    {
        if(c[1+b1]!=c[n-b2])
        {
            cnt++;
        }
        a[1+b1]-=1;
        a[n-b2]-=1;
        if(a[1+b1]==0)
        {
            b1++;
        }
        if(a[n-b2]==0)
        {
            b2++;
        }
    }
    cout << cnt;
    return 0;
}
