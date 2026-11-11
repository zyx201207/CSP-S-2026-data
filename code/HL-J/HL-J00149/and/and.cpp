#include<bits/stdc++.h>
using namespace std;
const int N = 2e5;
int a[N+5];
bool cmp(int p , int q){
    return p>q;
}
int main(){
    freopen("and.in" , "r" , stdin);
    freopen("and.out" , "w" , stdout);
    int n,m,ans = -1 , tmp;
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        cin>>a[i];
    sort(a+1 , a+1+n , cmp);
    for(int i=2; i<=m; i++){
        ans = a[i] & a[i-1];
    }
    cout<<ans;
    return 0;
}


