#include<bits/stdc++.h>
using namespace std;
const int N = 2e5;
int n, m;
long long ans;
struct node{
    long long n;
    int k;
} a[N + 10];
bool cmp(node a, node b){
    return a.k > b.k;
}
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        long long temp;
        cin >> temp;
        a[i].n = temp;
        while(temp){
            temp = (temp >> 1);
            a[i].k++;
        }
    }
    sort(a + 1, a + n + 1, cmp);
    ans = a[1].n;
    for(int i = 2; i <= m; i++) ans = ans & a[i].n;
    cout << ans;
    return 0;
}
