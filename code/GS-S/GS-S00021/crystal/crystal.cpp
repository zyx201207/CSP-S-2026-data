#include<iostream>
using namespace std;
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int n, m, x=0;
    cin>>n>>m;
    int a[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if((n+m)/2>a[i]){
            x++;
        }
    }
    cout<<x;
    return 0;
}
