#include <bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500050];
bool check(int x){
    long long summ = 0;
    int cnt = 0;
    for(int i = x;i >= 1;i--){
        summ += (a[x] - a[i]);
        cnt++;
        if(summ > m){
            cnt--;
            break;
        }
    }
    int i = x+1;
    while(a[i] == a[x]){
        cnt++;
        i++;
    }
    // cout << cnt << " " << x << endl;
    return x > cnt;
}
int search(int l,int r){
    if(l == r){
        if(check(l)){
            return l-1;
        }else{
            return l;
        }
    }
    // cout << l << " " << r << endl;
    int mid = (l+r)/2;
    if(check(mid))search(l,mid);
    else search(mid+1,r);
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    // int ans = 0;
    // for(int i = 1;i <= 315275;i++){
    //     ans += (a[315275]-a[i]);
    // }
    // cout << ans << endl;
    // cout << a[315275] << " " << a[315829] << " " << a[314919] << endl;
    int x = search(1,n);
    long long summ = 0;
    int cnt = 0;
    for(int i = x;i >= 1;i--){
        summ += (a[x] - a[i]);
        cnt = i;
        if(summ > m){
            cnt++;
            break;
        }
    }
    int i = x;
    while(a[i] == a[x]){
        i++;
    }
    cout << i-cnt << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}