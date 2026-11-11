#include<bits/stdc++.h>
using namespace std;
int a[500086],m,cy[500086],n,mm[300056]={0},p;
int c[300056]={0};

void fcy()
{
	for(int i=1;i<=n;i++) cy[i]=a[i];
}
void fz()
{
	for(int i=1;i<=m;i++) c[i]=0;
}

void take(int an)
{
	int i=1;
	while(i<=p){
		if(cy[i]==an){
			p=i;
			return;
		}
		i++;
	}
	cy[p+1]=an;
	p++;
}

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);

	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		p=0;
		for(int j=i;j<=n;j++)
		{
			take(a[j]);
		}
		fz();
		for(int z=1;z<=p;z++)
		{
			
			if(c[cy[z]]==0) {
				mm[cy[z]]++;
				c[cy[z]]=1;
			}
		}
	}
	for(int i=1;i<=m;i++) {
		cout<<mm[i]<<' ';
	}
	
	fclose(stdin);
	fclose(stdout);
}
