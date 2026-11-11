#include<bits/stdc++.h>
using namespace std;
int m,n,amin[100000],amax;
int a[100000];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            amin[i]=min(a[i],a[j]);
        }
    }
    for(int i=1;i<=n;i++){
        amax=max(amin[i],amin[i-1]);
    }
    cout<<amax;
    return 0;
}

