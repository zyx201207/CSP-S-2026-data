#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
long long a[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n ;
    long long m;
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++)cin >> a[i];
    sort(a+1,a+n+1);
    int x = 1;
    while(m - x*(a[x+1]-a[x])>0){
        while(a[x+1]==a[x])x++;
        m -= x*(a[x+1]-a[x]);
        x++;
    }
    if(m-x*(a[x+1]-a[x]) == 0){
        x++;
        while(a[x+1]==a[x])x++;
    }
    for(int i = x; i <= n ; i++){
        if(a[i] == a[i+1])x++;
        else break;
    }
    cout << x;
    return 0;
}
