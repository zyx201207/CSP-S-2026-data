#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);

	int n,m,a=0,l=0;
	int nm[5008]={0};int mo[3008]={0};int vv[5008]={0};int rt[3008]={0};

	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>nm[i];
	}
	for(int i=0;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			mo[a]=nm[j];
			vv[mo[a]]=vv[mo[a]]+1;
			if(vv[mo[a]]==2)
			{
				l=mo[a];
				mo[a]=0;
				a--;
				while(vv[ l ]>1)
				{
					if(mo[a]==l)
					{
						vv[ l ]=1;
					}
					else
					{
						mo[a]=0;
						a--;
					}
				}
			}
			a++;
		}
		
		for(int p=0;p<=a;p++)
		{
			if(mo[p]>0)
			{
			rt[mo[p]]=rt[mo[p]]+1;
			}
			vv[p]=0;
			mo[p]=0;
		}
		for(int p=0;p<n;p++)
		{
			
			vv[p]=0;
			mo[p]=0;
		}	
		a=0;	
		
	}
	for(int i=1;i<=m;i++)
	{
		cout<<rt[i]<<' ';
	}



	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
