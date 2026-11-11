#include<bits/stdc++.h>

using namespace std;
int c1,s1,c2,s2;
char a,b;
bool w=false,x=false,y=false,z=false;
int main(){
  freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>a>>c2>>s2>>b;
    if(c1==c2)w=true;
    if(w && s1==s2)x=true;
    if(w && x && ((a<='C' && b<='C') || (a>'C' && b>'C')))y=true;
    if(w && x && y && (a==b+1 || b==a+1 || (a=='D' && b=='F') || (a=='F' && b=='D')))z=true;
    if(a=='C')z=false;
    cout<<w<<x<<y<<z;
    return 0;
}
