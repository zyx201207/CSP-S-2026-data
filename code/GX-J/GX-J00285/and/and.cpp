#include <bits/stdc++.h>
using namespace std;
bool cmp(long long x,long long y){
    return x>y;
}
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
long long a[200005];
int n,m;
cin>>n>>m;
for(int i=0;i<n;i++){
    cin>>a[i];
}
sort(a,a+n,cmp);
long long t=a[0];
for(int i=1;i<m;i++){
    t=(t&a[i]);
}
cout<<t;
return 0;
}
