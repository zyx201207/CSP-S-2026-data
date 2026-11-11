#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int c,t;
struct nm
{
	int way,ti=114514,fang;
}a[2000001];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d %d\n",&c,&t);
	while(t--)
	{
		int n,d;
		scanf("%d %d\n",&n,&d);
		for(int i=1;i<=n;i++) scanf("%d ",&a[i].way);
		a[1].ti=0;
		for(int x=1;x<n;x++)    //start
			for(int y=1;y<=d&&a[x].way+y<=a[n].way;y++)  //increase
			{
				if(a[x+y].ti==a[x].ti+1) a[x+y].fang++;
				if(a[x+y].ti>a[x].ti+1) //a[x+y].ti=min(a[x+y].ti,a[x].ti+1);
				{
					a[x+y].ti=a[x].ti+1;
					a[x+y].fang=1;
				}
			}
		//for(int i=1;i<=n;i++) printf("%d %d//",a[i].ti,a[i].fang);
		//cout<< endl;
		int ans=0;
		for(int i=1;i<=n;i++)
			if(a[i].ti!=0&&a[i].fang%2==0) ans++;
		printf("%d\n",ans);
	}
	return 0;
}
