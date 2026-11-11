#include <bits/stdc++.h>
using namespace std;
int a[500005];
int main()
{
    freopen("crystal.in","r","stdin");
    freopen("crystal.out","w","stdout");
    int n, m, sum = 0,cnt = 0;
    bool b = 0;
    cin >> n >> m;
    for (int i = 1;i <= n;i++){
        cin >> a[i];
        sum += a[i];
    }
    sum = a[n/2+1];
    int j = 1;
    while (!m<=0){
        if (a[j] >= sum)
        {
            j++;
            continue;
        }
        if (a[j] < sum)
        {
            m--;
            a[j]++;
        }
    }
    for (int i = 1;i <= n;i++){
        if (a[i] == sum)
        {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
