#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200005];
long long maxn=-1;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxn=max(maxn,a[i]);
    }
    long long num=1;
    for(int i=1;i<=n;i++){
        num&=a[i];
    }
    if(m==1)cout<<maxn;
    else if(m==n){
        cout<<num;
    }
    return 0;
}
