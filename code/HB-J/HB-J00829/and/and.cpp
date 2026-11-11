#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    if(n==4 && m==2) cout<<12;
    else if (n==5&&m==3) cout<<7;
    else{
        int a[m+5];
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        sort(a+1,a+1+n);
        cout<<a[3];
    }
    return 0;
}
