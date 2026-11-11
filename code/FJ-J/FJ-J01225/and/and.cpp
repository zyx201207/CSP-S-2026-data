#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int number1,number2,number3=0,a[1000000]={0};
	int result;
	
	cin>>number1>>number2;
	for (int i=0;i<number1;i++)
	{
		cin>>number3;
		for (int j=0;j<i;j++)
		{
			if (number3>=a[j])
			{
				for(int k=j;k<number2;k++)
				a[k+1]=a[k];
				a[j]=number3;
			}
			else
			a[i]=number3;
		}
	}
	
	result=a[number2-1];
	
	cout<<result<<endl;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
