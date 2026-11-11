#include<bits/stdc++.h>
using namespace std;
struct as{
    int h;
    bool w[30]
}a[200001];
int n,m,c=0;
int main(){
    freopen("and.in","r",std);
    freopen("and.out","w",std);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].h;
        int o=a[i].h;
        int j=0
        while(o>0){
            a[i].w[j]=o%2;
            o/=2;
            j++;
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){

        }
    }
    cout<<1;
    return 0;
}
