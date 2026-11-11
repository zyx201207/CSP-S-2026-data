#include <bits/stdc++.h>
using namespace std;
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
long long n,m,a;
cin>>n >>m;
for(int i = 1;i<=n;i++){
    cin >> a;
    m = a;
    if(a<=m){
        m = a;
    }
}
cout <<m;
return 0;
}
