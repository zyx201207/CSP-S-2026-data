#include <bits/stdc++.h>
using namespace std;
long long n,m,a[100005];
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
cin >> n >> m;
bool flag = true;
for (int i = 1;i <= n;i++){
cin >> a[i];
}
sort(a + 1,a + n + 1);
for (int i = 1;i <= n;i++){
if(i > 2 && a[i] - a[i - 1] != a[i - 1] - a[i - 2])flag = false;
}
if(flag == true){
int cnt = 0;
for (int i = n - 1;i >= 1;i--){
if(m - (a[n] - a[i]) >= 0){
m -= a[n] - a[i];
cnt++;
}
}
cout << cnt + 1;               
}
else{
int cnt = 0,maxans = 0;
for (int i = n;i >= 2;i--){
cnt = 0;
int tot = m;
for (int j = i - 1;j >= 1;j--){
if (tot - (a[i] - a[j]) >= 0){
tot -= a[i] - a[j];
cnt++;
}
else break;
}
if(cnt > maxans)maxans = cnt;
}
cout << maxans + 1;
}
return 0;
}
