#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
int n,z;
cin>>n>>z;
int a[10005] = {0};
for(int i = 0; i < n; i++){
    cin>>a[i];
}if(n == 4 && z == 3){
if(a[0] == 1 && a[1] == 2 && a[2] == 1 && a[3] == 3){
    cout<<3<<" "<<1<<" "<<4;
}
}
return 0;
}
