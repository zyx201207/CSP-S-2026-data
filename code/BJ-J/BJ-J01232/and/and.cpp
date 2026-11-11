#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
    return x > y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","r",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    long long int n,m,a[200005];
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        cin >> a[i];
        if(i != 9&&a[i] > a[i - 10]) swap(a[i],a[i - 10]);
        if(i != 8&&a[i] > a[i - 9]) swap(a[i],a[i - 9]);
        if(i != 7&&a[i] > a[i - 8]) swap(a[i],a[i - 8]);
        if(i != 6&&a[i] > a[i - 7]) swap(a[i],a[i - 7]);
        if(i != 5&&a[i] > a[i - 6]) swap(a[i],a[i - 6]);
        if(i != 4&&a[i] > a[i - 5]) swap(a[i],a[i - 5]);
        if(i != 3&&a[i] > a[i - 4]) swap(a[i],a[i - 4]);
        if(i != 2&&a[i] > a[i - 3]) swap(a[i],a[i - 3]);
        if(i != 1&&a[i] > a[i - 2]) swap(a[i],a[i - 2]);
        if(i != 0&&a[i] > a[i - 1]) swap(a[i],a[i - 1]);
    }sort(a,a + n,cmp);
    if(m == 1) cout << a[0];
    if(m == 2) cout << max(a[0] & a[1],a[0] & a[2]);
    if(m == n - 1){
        long long int cnt = a[0];
        for(int i = 1;i < n - 2;i++){
            cnt &= a[i];
        }cout << max(cnt & a[n - 2],cnt & a[n - 1]);
    }
    if(m == n){
        long long int cnt = a[0];
        for(long long int i = 1;i < n;i++){
            cnt &= a[i];
        }cout << cnt;
    }else{
        long long int cnt = a[0];
        for(int i = 1;i < m;i++) cnt &= a[i];
        cout << cnt;
    }
    return 0;
}