#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
long long n,m,a[N],maxn=-1;
long long jz(int n){
    int a;
    while(n){
        a=n%2;
        n/=2;
    }
    return a;
}
int cmp(int a,int b){
     return a>b;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>=maxn)maxn=a[i];
    }
    cout<<maxn;
    return 0;
}
