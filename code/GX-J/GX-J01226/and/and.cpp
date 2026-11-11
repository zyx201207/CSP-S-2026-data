#include <bits/stdc++.h>
using namespace std;
long long n,m,e=2;
int a[10000000];
int c=-1,b;
int main(){
  freopen("and.in","r",stdin);
   reopen("and.out", "w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
       cin>>a[i];
    }
    sort(a+1,a+n+1);
    b=a[n]&a[n-1];
    while(m-2>0){
        b=b&a[n-e];
        e++;
        m--;

    }
    cout<<b;
    return 0;
}
