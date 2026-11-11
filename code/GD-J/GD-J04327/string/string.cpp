#include<cstdio>
char a[10000010]={0};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,x=1,u=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int y;
		char s;
		scanf("%d %c",&y,&s);
		for(int j=0;j<y;j++){
			a[x]=s;
			x++;
		}
	}
	if(x%2==0){
		for(int i=1;i<=x/2;i++){
			if(a[i]!=a[x-i])u++;
		}
	}
	else if(x%2==1){
		for(int i=1;i<=(x-1)/2;i++){
			if(a[i]!=a[x-i])u++;
		}
	}
	printf("%d",u);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
