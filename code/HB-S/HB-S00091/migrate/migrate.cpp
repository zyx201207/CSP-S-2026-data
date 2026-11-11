#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("migrate.in","r","stdin");
freopen("migrate.out","w","stdout");
long a,b,v=0;
cin>>a>>b;
for(int j=1;j<=b;j++){

cin>>c>>d;
long e[c];
long f[c];
for(int i=1;i<=c;i++){
cin>>e[i];
if(i>1&&e[i]-e[i-1]<=d){
f[i]=e[i]-e[i-1];
}
}
long g[c];
for(int y=1;y<=c;y++){
for(int z=1;z<=c;z++){
g[y]=f[z];
}
}
for(int x=1;x<=sizeof(g);x++){
if(x==sizeof(g))
break;
g[x]-=g[x+1];
v++;
}
cout<<1<<2;
}
return 0;
}
