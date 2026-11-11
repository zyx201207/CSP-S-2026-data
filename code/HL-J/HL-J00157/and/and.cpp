#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m,s,maxn=0;

    cin>>n>>m;
    for(int i =1;i<=n;i++){
        cin>>a[i];
    }
    cout<<a[n-1];
}
