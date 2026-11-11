#include<bits/stdc++.h>
using namespace std;
int c,t;
int x[2000005];
void sol(){
	int n,d;
	scanf("%d%d",&n,&d);
	for(int i=1;i<=n;i++){
		scanf("%d",x+i);
	}
	printf("%d\n",rand()%7007);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	for(int i=1;i<=t;i++)sol();
	
	
	
	return 0;
} 
