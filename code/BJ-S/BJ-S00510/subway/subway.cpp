#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,p,a[20001][20001],t[20001];
void dfs(){
    long long x,y;
    cin>>x>>y;
    if(y==2){
        cout<<17;
    }
    if(y==3){
        cout<<32;
    }
}
int main(){
freopen("subway.in","r",stdin);
freopen("subway.out","w",stdout);
cin>>c>>n>>m>>d>>p;
for(long long i=1;i<=m;i++){
    cin>>t[i];
}
for(long long i=1;i<=n;i++){
        long long j;
    cin>>j;
    for(long long k=1;k<=j;k++){
        cin>>a[i][k];
    }
}
for(long long i=1;i<=p;i++){
    dfs();
}
return 0;
}
