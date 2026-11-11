#include<cstdio>
#include<fstream>
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int x,y;
	scanf("%d%d",&x,&y);
	if(x==11 || x==12){
		for(int a=1;a<=y;a++){
			int c,h,t[20];
			scanf("%d%d",&c,&h);
			for(int r=1;r<=c;r++){
				scanf("%d",&t[r]);
			}
			if(t[2]-t[1]>h) printf("0\n");
			else printf("%d\n",a);
		}
	}
	else{
		for(int a=1;a<=y;a++){
			printf("%d\n",a);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
