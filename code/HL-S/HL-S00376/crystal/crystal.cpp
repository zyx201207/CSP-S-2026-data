#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
#define ll long long
ll n, a[N], m, ans = 0, sum=0;
bool cmp(ll x, ll y){
return x < y;
}

int main(){
freopen("crystal.in", "r", stdin);
freopen("crystal.out", "w", stdout);
ios::sync_with_stdio(false);
cin.tie(nullptr);
cin >> n >> m;
for(int i = 1;i <= n;i++)cin>>a[i];
sort(a+1, a+n+1, cmp);
for(int i = 1;i <= n;i++){
sum = a[i] - a[i - 1];
ans += (i-1)*sum;
if(ans>=m){
cout << i - 1 << endl;
return 0;
}
}
cout << n;
return 0;
}
