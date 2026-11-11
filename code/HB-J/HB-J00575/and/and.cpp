#include <iostream>
#include <algorithm>
int a,b;
int c[200005];
int ans;
void f(int x,int y,int s,int q){
    if(y==1){
        if(s>ans){
            ans=s;
        }
    }
    else{
        for(int i=x+1;i<=q;i++){
            f(i,y-1,s&c[i],q);
        }
    }
}
using namespace std;
int main(){
    froepen("and.in","r","stdin");
    froepen("and.out","w","stdout");
    cin >> a >> b;
    for(int i=1;i<=a;i++){
        cin >> c[i];
    }
    for(int i=1;i<=a;i++){
        f(i,b,c[i],a);
    }
    cout << ans;
    return 0;
}
