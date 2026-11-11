#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,a[100005],b[100005],x=0;
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    b[1]=a[1];
    for(int i=1;i<=n;i++){
        b[i]=a[i];
        while(1){
            int s=1;
            for(int j=1;j<=m;j++){
                b[i]=b[i] and a[i+s];
                s++;
            }
            break;
        }
        if(b[i]>x){
            x=b[i];
        }
    }
    cout<<x;
    return 0;
}
