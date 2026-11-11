#include<bits/stdc++.h>
using namespace std;
const int N = 5e5;
int a[N+5] , dp[N+5];
int main(){
    freopen("card.in" , "r" , stdin);
    freopen("card.out" , "w" , stdout);
    int n, m , ci=0;
    vector<int> p(N);
    cin>>n>>m;
    for(int i=1; i<+n; i++)
        cin>>a[i];
    while(ci<=n){
        for(int i=1; i<=n; i++)
            if(a[i])
        ci++;
    }
    for(int i=1; i<=m; i++)
        cout<<dp[i];
    return 0;
}
