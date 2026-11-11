#include<bits/stdc++.h>
using namespace std;
int c,t;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	srand(time(NULL));
	scanf("%d%d",&c,&t);
	while(t--) printf("%d",rand()%20000+1);
	return 0;
}
