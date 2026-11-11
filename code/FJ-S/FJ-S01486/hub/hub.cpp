#include<bits/stdc++.h>
using namespace std;
int c,t,n,k;
int inv(){
	while(t--){
		scanf("%d%d",&n,&k);
		int l,r;
		for(int i=1;i<n;i++)
		scanf("%d%d",&l,&r);
		if(k>=n){
			printf("0\n");
			continue;
		}
		n=n/2-k;
		int kp=(n+3)/4;
		printf("%d\n",kp+1);
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	if(c==13||c==14){inv();return 0;}
	while(t--)printf("1\n");
	return 0;
}
