#include<bits/stdc++.h>
using namespace std;

int a[100005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    int n;
    cin >> n;

    int cnt = 0;
    string c;

    for(int i=1;i<=n;i++)
    {
        cin >> a[i] >> c[i];
    }
    for(int i=1;i<=n;i++)
    {
        if(c == sum)
        {
            cnt++;
        }
        else
        {
            continue;
        }
    }
    cout << cnt;
    return 0;
}

