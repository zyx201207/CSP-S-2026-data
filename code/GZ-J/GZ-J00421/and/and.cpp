#include<bits\stdc++.h>
using namespace std;

int main(){
    default("and.in","r");
    default("and.out","w");
    int n,m,x=0;
    cin>>n>>m;
    int a[n],b[m];
    for(int i=0;i<=n;i++){
        cin>>a[i];
    }
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            b[i]=max(b[i],a[j]);
            if(b[i]==a[j]){
                a[j]=0;
            }
        }
    }
    for(int i=0;i<=m;i++){
        x=x and b[i];
    }
    cout<<x<<endl;
    return 0;
}
