//hub.cpp
#include<bits/stdc++.h>
using namespace std;

int c,t,u[2000005],v[2000005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		int n,k;
		scanf("%d%d",&n,&k);
		for(int i=1;i<n;i++) scanf("%d%d",&u[i],&v[i]);
		printf("%d\n",u[n/2]+v[n/2]);
	}
	return 0;
}
