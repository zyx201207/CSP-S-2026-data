#include<bits/stdc++.h>
using namespace std;
char zimu[10000000];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,a,c,z = 0,num = 0,cnt = 0;
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> a >> c;
        num += a;
        for(int j = 1;j <= a;j++)
        {
            zimu[z] = c;
            z++;
        }
    }
    int l = 0,r = n/2;
    for(int i = 1;i <= num/2;i++)
    {
        if(zimu[l] != zimu[r])
        {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
