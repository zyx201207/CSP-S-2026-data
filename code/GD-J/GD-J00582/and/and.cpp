#include <iostream>
using namespace std;
int a[200005],maxx=0,n,m;
void f(int x,int y,int z){
    if(y==m){
        maxx=max(maxx,z);
        return;
    }
    if(n==x)return;
    f(x+1,y,z);
    f(x+1,y+1,(z & a[x+1]));
}
int main(){
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    f(0,0,262143);
    cout << maxx;
    return 0;
}
