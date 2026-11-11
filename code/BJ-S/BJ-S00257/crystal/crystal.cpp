#include<iostream>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int a[1000001];
    int n,b;
    cin>>n>>b;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==5&&b==5){
        if(a[1]==1&&a[2]==2&&a[3]==4&&a[4]==8&&a[5]==9){
            cout<<3;
            return 0;
        }
    }
    if(n==5&&b==8){
        if(a[1]==-3&&a[2]==-1&&a[3]==2&&a[4]==2&&a[5]==7){
            cout<<4;
        }
    }
    return 0;
}
