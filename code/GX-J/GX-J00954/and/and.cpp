#include <bits/stdc++.h>
using namespace std;
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
int n,m,a[1000000];
cin >> n >> m;
int maxn=0;
int cnt=0;
for(int i=1;i<=n;i++){
    cin >> a[i];
    cnt=max(cnt,a[i]&a[i+1]);
    maxn=max(maxn,a[i]&a[i-1]);
}
maxn=max(maxn,cnt);
cout << maxn;
return 0;
}

