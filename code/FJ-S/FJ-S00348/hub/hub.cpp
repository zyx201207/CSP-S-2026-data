#include<bits/stdc++.h>
using namespace std;
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
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	return 0;
}