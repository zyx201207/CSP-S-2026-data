#include <bits/stdc++.h>
using namespace std;
const int N=2*1e5+5;
using LL=long long;
int n,a[N];
char c[N];

LL f(){
    LL res=0;
    int p=1,q=n;
    while(p<q){
        if(a[p]>a[q]){
            a[p]-=a[q];
            if(c[p]!=c[q]) res+=a[q];
            q--;
        }
        else if(a[p]==a[q]){
            if(c[p]!=c[q]) res+=a[p];
            p++; q--;
        }
        else if(a[p]<a[q]){
            a[q]-=a[p];
            if(c[p]!=c[q]) res+=a[p];
            p++;
        }
    }
    return res;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    cout<<f();
    return 0;
}
