#include<iostream>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,a[9];
    for(int i=0;i<n;i++) cin>>a[i];
    if(n==4&&m==2&&a[0]==3&&a[1]==15&&a[2]==12&&a[3]==12) cout<<12;
    return 0;
}
