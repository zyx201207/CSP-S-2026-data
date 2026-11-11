#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200005];

bool cmp(long long x,long long y){
    return x>y;
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n,cmp);
    cout<<a[m-1];


    return 0;
}
