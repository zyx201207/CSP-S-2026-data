#include <bits/stdc++.h>
using namespace std;
long long a[500005];
long long h[500005];
long long k[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,Max = 0 ;
    long long m;
    cin >>n>>m;
    for (int i = 1;i<=n;i++)
        cin >> a[i];
    sort(a,a+n);
    for (int i = 1;i<n-1;i++)
        h[i] = a[i+1]-a[i];
    for (int i = 1;i<n;i++)
        k[i] = h[i-1]+k[i-1];
    for (int i = 0;i<n;i++){
        for (int j = i+1;j<n;j++){
            int y = k[j] - k[i];
            if (y <= m && j-i>Max)
                Max =  j - i;
            else if (y > m)
                break;
        }
    }
    cout << Max;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
