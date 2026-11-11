#include <bits/stdc++.h>
using namespace std;
int n;
long long m,a[500007],c[500007];
bool cmp(long long x,long long y){
    return x < y;
}
bool check(int x){
    long long minn = 0x3f3f3f3f3f3f3f3f;
    for(int i = x;i <= n;i++){
        minn = min((a[i] * x - (c[i] - c[i - x])),minn);
    }
    //cout << minn << "\n";
    if(minn <= m)return 1;
    else return 0;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a + 1,a + n + 1,cmp);
    for(int i = 1;i <= n;i++){
        c[i] = a[i] + c[i - 1];
    }
    int l = 1,r = n;
    while(l < r){
        int mid = l + (r - l + 1) / 2;
        if(check(mid)){
            l = mid;
        }
        else{
            r = mid - 1;
        }
        //cout << l << " " << r << " " << mid << "\n";
    }
    cout << l;
    return 0;
}