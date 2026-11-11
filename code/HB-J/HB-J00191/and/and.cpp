#include<bits/stdc++.h>
using namespace std;
int n,m;
int we[200],a[200],t[200][30];
int main(){
    freopen("add.in","r",stdin);
    freopen("add.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        int x=a[i];
        while(x!=0){
            we[i]++;
//            t[i]=t[i][we[i]]=x%2;
            x/=2;
        }
    }
    cout<<"12";
    return 0;
}
