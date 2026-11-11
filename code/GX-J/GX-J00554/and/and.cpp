#include <bits/stdc++.h>
using namespace std;
int a[200001],b[31],c[200001],d[200001];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin >> n >> m;
    //cout << n << m;
    for (int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    //for (int i = 1;i <= n;i++) cout << a[i] << " ";
    if (m == 1){
        cout << a[n];
        return 0;
    }
    limit = 1;
    for (int i = 1;i <= n;i++){
        while (a[i] <= pow(2,limit)) limit++;
        c[i] = limit - a[i];
    }
    for (int i = 1;i <= n;i++) d[i] = c[i];
    sort(c+1,c+n+1);
    for (int i = 1;i <= m;i++){
        for (int j = 1;j <= n;j++){
            if (c[n-i] == d[j]) b[i] = a[j];
        }
    }
    cout << min(b[1],b[2]);

    //for (int i = 1;i <= n;i++) cout << c[i] << endl;
    return 0;
}
