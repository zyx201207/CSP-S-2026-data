#include<bits/stdc++.h>
using namespace std;

int c,t;

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	srand(time(NULL));
	if(c>=1&&c<=3){
		while(t--){
			printf("%d\n",rand()%2+1);
		}
	}
	else if(c>=4&&c<=8){
		while(t--){
			printf("%d\n",rand()%20+1);
		}
	}
	else if(c>=9&&c<=12){
		while(t--){
			printf("%d\n",rand()%200+200);
		}
	}
	else{
		while(t--){
			printf("%d\n",rand()%5000+10000);
		}
	}
	return 0;
}

