#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
int a[N],c[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i = 0;i<n;i++){
            int b;
        cin >> b;
        a[b]++;
    c[b] = i+1;
    }
    for(int i = 1;i<=m;i++){
        cout << c[i-1+a[i]] <<' ';
    }
    return 0;
}
