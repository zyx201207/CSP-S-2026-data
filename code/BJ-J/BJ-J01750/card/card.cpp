#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N = 2e5;
int a[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    bool f = true;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        cout << i << " ";
        if(a[i] == a[i - 1]) f = false;
    }
    
    return 0;
}