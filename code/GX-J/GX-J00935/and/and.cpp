
#include<bits/stdc++.h>
using namespace std;
int a[10000005];
int n,m;
int main()
{
    int k=0;
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    for(int i=m-1;i>=1;i--){
        k+=a[i] and a[i-1];
    }
    cout << k;
    return 0;
}
