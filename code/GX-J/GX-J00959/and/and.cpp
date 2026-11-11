#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[1000005];
int b[1000005];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i<=n;i++)
        cin >> a[i];
    for(int i = 1;i<=n;i++){
        b[i]=(a[i] & a[i+1])
    }
    sort(b+1,b+n+1,cmp);
    cout << b[1];
    return 0;
}
