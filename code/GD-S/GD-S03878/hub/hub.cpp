#include<bits/stdc++.h>
using namespace std;
const int N=1e6+2;
int op,_,n,m;
int main(){
	freopen("hub.in","r",stdin),freopen("hub.out","w",stdout);
	scanf("%d %d\n",&op,&_);
	while(_--){
		scanf("%d %d",&n,&m);
		for(int i=1,u,v;i<n;++i) scanf("%d %d",&u,&v);
		printf("%d\n",n/m-1);
	}
	fclose(stdin),fclose(stdout);
	return 0;
}
