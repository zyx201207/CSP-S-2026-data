#include <iostream>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,f;
    cin >> n >> m;
    long long b[n];
    for(int i = 1;i <= n;i++)
    {
        cin >> b[i] >> " ";
    }
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= m;j++)
        {
            int a = b[i] & b[j];
            int x = b[i + 1] & b[j + 1];
        }
    }
    cout << max(a,x);
    return 0;
}
