#include<bits/stdc++.h>
using namespace std;
long long a[1000000], cnt, all[1000000];
int main(){
freopen("and.in","s",stdin);
freopen("and.out","w",stdout);
int n, m, MAX = 0;
cin >> n >> m;
for(int i = 0 ; i < n ; i++)
    cin >> a[i];
all[0] = a[0] & a[1];
for(int i = 1 ; i < n ; i++){
		all[i] = a[i - 1] & a[i];
        if(MAX < all[i])
        MAX = all[i];
}
cout << MAX;
return 0;
}
