#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int paishu,zhongshu,a[10000]={0},b[10000]={0},c[10000]={0};
	
	cin>>paishu>>zhongshu;
	for (int i=0;i<paishu;i++)
	cin>>a[i];
	
	for (int i=0;i<paishu;i++)
	{
		for (int j=i;j<paishu;j++)
		{
			b[j-i]=a[j];
			for (int k=0;k<j-i;k++)
			{
				if(b[k]==b[j-i])
				for (int l=k;l<j-i;l++)
				b[l]=0;
			}
		}
		for (int j=0;j<paishu;j++)
		{
			c[b[j]-1]+=1;
		}
	}
	
	cout<<c<<endl;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
