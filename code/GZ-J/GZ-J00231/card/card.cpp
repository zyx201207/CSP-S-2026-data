//GZ-J00231,遵义市第十二中学,韩冰洁
#include<bits/stdc++.h>
using namespace std;
int n,a[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        if(a[x]!=0){
            for(int j=x;j<=n;j++){
                a[j]=0;
            }
        }
        else{
            a[j]++;
        }
    }
    for(int i=1;i<=n;i++){
        if(a[i]!=0){
            cout<<a[i];
        }
    }
    return 0;
}
