#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    long long n, m, a[1000000], maxx=-1;
    cin >> n >> m;
    if(m==1)
    {
        for(int i=0; i<n; i++)
        {
            cin >> a[i];
            if(a[i]>maxx) maxx = a[i];
        }
    cout << maxx;
    return 0;
    }
    for(int i=0; i<n; i++) cin >> a[i];
    if(m==2)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++) if((a[i] & a[j]) > maxx && a[i] != a[j]) maxx = (a[i] & a[j]);
        }
        cout << maxx;
    }
    return 0;
}