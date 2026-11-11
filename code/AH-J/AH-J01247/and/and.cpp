#include<bits/stdc++.h>
using namespace std;
int n,a[200050],m,Max;
int q(int x,int y){
    int t;
    for(int i=x+1;i<=n;i++){
        if(y==m) return a[i];
        t=q(i,y+1)&a[i];
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<=n;i++){
        cin>>a[i];
    }
    Max=q();
    cout<<Max;
    return 0;
}
//fang wei @)!#)@@!
