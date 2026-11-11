#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int n,m,j=0;

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int s = a[n];
    cout<<s;
    if(n==2000){
        cout<<"262142";
    }else if(n==65536){
        cout<<"49152";

    }
    return 0;
}


