//GZ-J00320     Îâº«·É 
#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+1];
	int s[10005];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<10005;i++)
	{
		s[i]=0;
	}
	int sum1=0,sum2=0,sum3=0;
	for(int i=0;i<n;i++)
	{
		s[i]=a[i];
		for(int j=0;j<n;j++)
		{
			if(s[i]==s[j])
			{
				for(int k=i;k<n;k++)
				{
					s[k]=0;		
				}		
			}		
		}
		if(s[i]==1)
		{
			sum1+=1;
		}
		if(s[i]==2)
		{
			sum2+=1;
		}
		if(s[i]==3)
		{
			sum3+=1;
		}
	}
	cout<<sum1<<' '<<sum2<<' '<<sum3;
	fclose(stdin);
	fclose(stdout);
}

