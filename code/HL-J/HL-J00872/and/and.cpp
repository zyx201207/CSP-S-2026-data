#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
int main(){
    freopen("and.cpp.in","r",stdin);
    freopen("and.cpp.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(m==1){
       cout<< a[n];
    }
    return 0;
}
