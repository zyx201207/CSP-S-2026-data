#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500001];
inline int rd(){
	int k=0,q=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-')q=-1;
		c=getchar();
	}while(isdigit(c)){
		k*=10,k+=c-48,c=getchar();
	}return k*q;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=rd(),n=rd(),m=rd(),d=rd(),q=rd();
	for(int i=1;i<=m;++i)w[i]=rd();
	return 0;
}