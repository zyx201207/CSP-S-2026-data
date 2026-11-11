#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
using namespace std;
const int N=5e5+10;
long long n,m,a[N],pre[N];
bool check(int x){
    for(int i=x;i<=n;i++){
        if(m>=(a[i]*x)-(pre[i]-pre[i-x]))
            return 1;
    }
    return 0;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        pre[i]=a[i]+pre[i-1];
    }
    long long l=0;
    long long r=n;
    while(l<r){
        long long mid=(l+r+1)/2;
        if(check(mid)) l=mid;
        else r=mid-1;
    }
    cout << l;
}