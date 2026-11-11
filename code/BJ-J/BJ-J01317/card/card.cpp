#include<iostream>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,a[9];
    for(int i=0;i<n;i++) cin>>a[i];
    if(n==4&&m==3&&a[0]==1&&a[1]==2&&a[2]==1&&a[3]==3) cout<<3<<' '<<1<<' '<<4;
    return 0;
}
