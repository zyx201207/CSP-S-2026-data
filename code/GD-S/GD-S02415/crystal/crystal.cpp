#include<bits/stdc++.h>
using namespace std;
long long cd[600000];
long long op[600000];
long long t[600000];
long long n,u;
long long m;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>t[i];
    }
    int r=1-t[1];
    sort(t+1,t+n+1);
    for(long long i=1;i<=n;i++){
        cd[i]=cd[i-1]+t[i];
        op[i]=t[i]*i-cd[i-1]+r;
        if(op[i]<=m)u=max(u,i);
    }
    if(t[1]==t[n])u=n-1;
    if(n=1)u=0;
    cout<<u+1<<endl;
    return 0;
}
