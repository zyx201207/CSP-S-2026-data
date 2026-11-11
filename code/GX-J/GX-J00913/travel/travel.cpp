#include <bits/stdc++.h>
using namespace std;
int main(){
freopen("travel1.in","r",stdin);
freopen("travel2.out","w",stdout);
string n,q,w,e,r,t,y,u;
string sum = "";
int gunmu = 0;
cin>>n>>q>>w>>e;
r = q[0]+q[1];
t = q[2];
y = e[0]+e[1];
u = e[2];
if(n==w){
    gunmu+=1;
    sum+="1";
    if(r==y){
    sum+="1";
    gunmu==1;
    if(t<="C"&&u<="C"||t>="D"&&u>="D"){
    sum+="1";
    gunmu+=1;
    if(t[0]-u[0]==1||t[0]-u[0]==-1){
    if(t=="C"&&u=="D"||u=="C"&&t=="D"){
        sum+="0";
        gunmu+=1;
    }
    else{
        sum+="1";
        gunmu+=1;
    }
}
else{
    sum+="0";
    gunmu+=1;
}
}
else{
    sum+="0";
    gunmu+=1;
}
}
else{
    sum+="0";
    gunmu+=1;
}
}
else{
    sum+="0";
    gunmu+=1;
}

for(int i = gunmu+1;i<4;i++){
    sum+="0";
}


cout<<sum;
return 0;
}
