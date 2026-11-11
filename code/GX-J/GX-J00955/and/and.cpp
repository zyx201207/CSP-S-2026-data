#include <bits/stdc++.h>
using namespace std;
long long a[200010];
int n,m;
long long q(int s,int x,long long jg){

    if(s>m){
        return jg;
    }
    jg=jg&a[x];
    for(int i=x+1;i<=n;i++){
        jg=max(q(s+1,i,jg),jg);
    }
    return jg;
}
int main()
{   freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long an=-1;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==1){
        cout<<a[1];
        return 0;
    }
    if(n==2){
        if(m==1){
            an=max(a[1],a[2]);
        }
        else{
            an=a[1]&a[2];
        }
        cout<<an;
        return 0;
    }
    for(int i=1;i<=n-m+1;i++){
        for(int j=i+1;j<=n;j++){
            an=max(an,q(2,j,a[i]));
        }

    }
    cout<<an;
    return 0;
}
