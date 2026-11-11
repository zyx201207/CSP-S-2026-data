#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin>>m>>n;

    int a[105];
    for(int i=1;i<=n;i++){

        cin>>a[i];
    }
    int maxs=a[i];
    for(int i=1;i<=n;i++){
        if(maxs%2!=0)maxs==a[i];
    }

cout<<maxs;
return 0;
}

