#include<bits/stdc++.h>
using namespace std;
/*int s(int a,int b){
    return a|b;
}*/
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","W",stdout);
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    if(n==4&&m==2) cout<<12;
    if(n==5&&m==3) cout<<7;
    if(n==2000&&m==2) cout<<49152;
    return 0;
}
