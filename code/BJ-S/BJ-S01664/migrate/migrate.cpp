#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6+5;
int n,d;
int p[N];
int to[N],fr[N],dp1[N],dp2[N];
int ans;
int get(int x,int a,int b,int y){
    int sa = 0,sb = 0;
    if(to[y-1] < to[y]){
        sb = dp1[to[y]]+to[y]-to[y-1]-1;
    }
    if(fr[x+1] > fr[x]){
        sa = dp2[fr[x]]+fr[x+1]-fr[x]-1;
    }
    return sa*sb;
}
void sol(){
    ans = 0;
    cin >> n >> d;
    for(int i = 1;i <= n;i++){
        cin >> p[i];
    }
    int j = n;
    for(int i = n;i >= 1;i--){
        while(j > i && p[j]-p[i] > d){
            j--;
        }
        to[i] = j;
    }
    j = 1;
    for(int i = 1;i <= n;i++){
        while(j < i && p[i]-p[j] > d){
            j++;
        }
        fr[i] = j;
    }
    for(int i = n;i >= 1;i--){
        dp1[i] = 1;
        if(to[i] > to[i-1] && to[i] != i){
            dp1[i] += to[i]-to[i-1]-1+dp1[to[i]];
        }
    }
    for(int i = 1;i <= n;i++){
        dp2[i] = 1;
        if(fr[i] < fr[i+1] && fr[i] != i){
            dp2[i] += fr[i+1]-fr[i]-1+dp2[fr[i]];
        }
    }
    for(int i = 1;i <= n;i++){
        int j = to[i];
        if(i != j && j != i+1){
            ans += to[j-1]-to[j-2];
        }
        if(i != j && j != i+1 && fr[j-1] == i && fr[i+1] > fr[i]){
            ans += (dp2[fr[i]]+fr[i+1]-fr[i]-1)*(to[j-1]-to[j-2]);
        }
        if(fr[i] != i && fr[i]+1 != i && to[fr[i]+1] == i && to[i-1] < to[i]){
            ans += (dp1[to[i]]+to[i]-to[i-1]-1)*(fr[fr[i]+2]-fr[fr[i]+1]);
        }
        int jj = to[j];
        if(i != j && j != i+1 && jj != j && (j-1 == i+1 || to[j-2] < jj) && to[j-1] == jj && fr[j-1] == i){
            ans += get(i,j-1,j,jj);
        }
    }
    cout << ans << '\n';
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin.tie(0),cout.tie(0);
    int __,_;
    cin >> __ >> _;
    while(_--){
        sol();
    }
}
/*
1 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989
*/
