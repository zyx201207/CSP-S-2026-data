#include<bits/stdc++.h>
using namespace std;
int n,m,b;
int a[1000];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(b<a[i]){
            b=a[i];
        }
    }
    if(m==1){
        cout<<b;
    }

return 0;
}
