#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<bitset>
using namespace std;
struct T {int x;int y;char c;};T input() {
T a={0,0,'0'};scanf("%d",&a.x);char c;do {
c=getchar();} while(!isdigit(c));do{a.y=10
*a.y+(c^48);c=getchar();} while(isdigit(c)
);a.c=c;return a;}int getAns(T x,T y) {int
ans=0;if(x.x!=y.x) return ans;ans|=(1<<3);
if (x.y!=y.y) return ans;ans|=(1<<2);if ((
x.c<='C')^(y.c<='C')) return ans;ans|=(2);
if((x.c+1)!=y.c&&(y.c+1)!=x.c) return ans;
ans|=1;return ans; }int main( ) {freopen (
"travel.in","r",stdin);T a=input(),b=input
();freopen("travel.out","w",stdout);bitset
<4> x = getAns(a,b);cout<< x <<std::endl;}
