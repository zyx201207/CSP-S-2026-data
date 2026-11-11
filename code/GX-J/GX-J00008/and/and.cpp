#include <bits/stdc++.h>
using namespace std;

long long a[20000000005];

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    int n,m;
    cin >>n >>m;
    for (int i=0;i<n;i++)
        cin >> a[i];

    int cnt = a[n];

    sort(a,a+n);
    //for(int i =0;i<n;i++){
        //if(a[i])

    for(int i=1;i<=m;i++)
        cnt = cnt & a[n-i];

    cout << cnt;

    return 0;
}
