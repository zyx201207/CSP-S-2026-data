#include<bits/stdc++.h>
using namespace std;
int main(){
long a,c=0,d,f;
cin>>a;
d=a;
long b[a],e[a];
for(int i=1;i<=2*a;i++){
    cin>>b[i]>>e[i];
    f+=e[i];
}
if(f%2==0){
    for(int j=1;j<=a;j++){
    if(b[j]!=b[d]){
        c++;
    }
    d--;
    }
}
if(f%2==1){
        for(int y=1;y<=a;y++){
    if(b[y]!=b[d]){
        c++;
    }
    d--;
    }
}
cout<<c/2;
    return 0;
}
