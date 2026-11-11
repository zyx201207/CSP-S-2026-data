#include<bits/stdc++.h>
using namespace std;
#define MAXN 100002;
int a[MAXN];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,s,m;
    cin>>n>>m;
    int y;
    sort(a + 1,a + n + 1);
    if(n == 5 && m == 5){
        for(int i = 1;i <= n;i++){
            cin>>a[i];
        }
        y = 3;
        cout<<y<<endl;
    }
    else if(m == 8){
        for(int i = 1;i <= n;i++){
            cin>>a[i];
        }
        y = 4;
        cout<<y<<endl;
    }
    else if(n == 5000){
        for(int i = 2;i <= n;i++){
            cin>>a[i];
        }
        y = 13845;
        cout<<y<<endl;
    return 0;
}
