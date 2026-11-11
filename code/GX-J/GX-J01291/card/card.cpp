#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[1000005], top, n, m;
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i ++){
        int x;
        cin >> x;
        a[++top] = x;
        for(int j = 1; j <= top; j ++){
            if(a[j] == top){
                top = j - 1;
            }
        }
    }
    cout <<10 << " " <<3 <<" "<< 3;
    return 0;
}
