#include<bits/stdc++.h>
using namespace std;

int n;
struct{
   int a;
   char b;
}c[200005];

int main(){

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>c[i].a>>c[i].b;
    }

    if(n==1){
        cout<<"0";
        return 0;
    }

    else cout<<c[1].a;

    return 0;

}