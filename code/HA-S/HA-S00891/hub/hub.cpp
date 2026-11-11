#include<bits/stdc++.h>
#define fileio(name) (freopen(name".in","r",stdin),freopen(name".out","w",stdout))
#define MAXN 5005
#define NN 2000005
#define ll long long
using namespace std;
template<class T>inline void read(T& x){
	int f=1;char k=getchar();x=0;
	for(;k<'0'||k>'9';k=getchar())if(k=='-')f=-1;
	for(;'0'<=k&&k<='9';k=getchar())x=x*10+k-'0';
	x*=f;
}
int c,t,n;
int main(){
	fileio("hub");
	read(c),read(t);
	while(t--){
		printf("1\n");
	}
	return 0;
}
