#include<bits/stdc++.h> 
using namespace std;
int a,b,e[5];
char c[4],d[4];
int r1(char f){
if('A'<=f<='C')
return 1;
return 0;
}
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
cin>>a>>c>>b>>d;
if(a==b)
e[1]=1;
a=(c[0]-'0')*10+c[1]-'0',b=(d[0]-'0')*10+d[1]-'0';
if(a==b&&e[1])
e[2]=1;
if(r1(c[2])==r1(d[2])&&e[2])
e[3]=1;
if(abs(int(c[2]-d[2]))==1&&e[3])
e[4]=1;
for(int i=1;i<=4;i++)
cout<<e[i];
return 0;
}





