#include<bits/stdc++.h>
using namespace std;
struct sbool{
	long long a;
	char b;
};
int n;
long long sum;
sbool h[100005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		int u;
		char s;
	    scanf(" %d %c",&u,&s);
		h[i].a=u;
		h[i].b=s;
	}
	int x=1,y=n,whilea=0;
	while(whilea==0)
	{
		if(h[x].a==0&&h[y].a==0)
		{
			whilea=1;
		}
		if(h[x].b==h[y].b)
		{
			if(h[x].a==h[y].a);
			{
				h[x].a=0;
				h[y].a=0;
				x++;
				y--;
			}
			if(h[x].a<h[y].a)
			{
				h[y].a-=h[x].a;
				h[x].a=0;
				x++;
			}
			else
			{
				h[x].a-=h[y].a;
				h[y].a=0;
				y--;
				
			}
		}
		else
		{
			if(h[x].a==h[y].a)
			{
				sum+=h[y].a;
				h[x].a=0;
				h[y].a=0;
				x++;
				y--;
			}
			else if(h[x].a<h[y].a)
			{
				sum+=h[x].a;
				h[y].a-=h[x].a;
				h[x].a=0;
				x++;
			}
			else
			{
				sum+=h[y].a;
				h[x].a-=h[y].a;
				h[y].a=0;
				y--;
				
			}
		}
	}
	printf("%d",sum);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
