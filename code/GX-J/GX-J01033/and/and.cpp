#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[200002];

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(m==1){
        k=0;
        for(int i=1;i<=n;i++) if(k<a[i]) k=a[i];
        cout<<k;
    }
    if(m==2){
        k=0;
        for(int i=1;i<=n-1;i++) for(int j=i+1;j<=n;j++) if(k<k & a[i]) k=k & a[i];
        cout<<k;
    }
    return 0;
}
