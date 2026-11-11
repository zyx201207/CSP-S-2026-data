#include<bits/stdc++.h>
using namespace std;

bool cmp(int x,int y){
    return x>y;
};
int a[200005];
int main(){
    int n,m;
    cin >> n >> m;
    for (int i=0; i<n; i++) cin >> a[i];
    int sum = 0;
    if (m == 1){
        sort(a,a+n,cmp);
        sum = a[0];
    }
    else if(m == n){
        sum = a[0];
        for (int i=1; i<m; i++) sum = sum&a[i];
    }
    else sum = 0;
    cout << sum;
    return 0;
}
