#include<cstdio>
#include<fstream>
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int x;
	scanf("%d%d",&x,&x);
	for(int a=1;a<=x;a++){
		printf("%d\n",a);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
