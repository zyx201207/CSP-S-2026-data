#include<bits/stdc++.h>
using namespace std;
int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n,a=0,b=0,j,e;
	/*for(int i=0;i<=n+1;i++)
	{
		scanf("%d %d",&j,&e);
	}
	*/
	scanf("%d",&n);
	if(n/2==0)
	{
		a=n/2;
		printf("%d",a);
	}
	else
	{
		b=(n+1)/2;
		printf("%d",b);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
