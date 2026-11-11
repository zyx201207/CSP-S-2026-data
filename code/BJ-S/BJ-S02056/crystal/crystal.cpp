#include<bits/stdc++.h>
using namespace std;
signed main(){
freopen ("crystal "," r",stdin);
freopen(" crystal","w",stdout);
int a[100005];
int n;
long long m;
int d;
cin>>n>>m>>d;
for(int i=1;i<=n;i++){
    int n=a[i];
    a[i]++;
}
for(int i=1;i<=m;i++){
    int d=a[i]*m;
    cout<<d;
}
return 0;
}
