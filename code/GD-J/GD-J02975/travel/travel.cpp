#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	freopen("travel.in","r",stdoin);
	freopen("travel.out","w",stdout);
	int a1,a2,b1,b2;
	char a3,b3;
	scanf("%02d %02d%c %02d %02d%c",&a1,&a2,&a3,&b1,&b2,&b3);
	bool f1 = 0,f2 = 0,f3 = 0,f4 = 0;
	if(a1 == b1)
	{
		f1 = 1;
		if(a2 == b2)
		{
			f2 = 1;
			if(a3>b3)
			{
				swap(a3,b3);
			}
			if(((a3 == 'A'||a3 == 'B'||a3 == 'C')&&(b3 == 'A'||b3 == 'B'||b3 == 'C'))||((a3 == 'D'||a3 == 'F')&&(b3 == 'D'||b3 == 'F')))
			{
				f3 = 1;
				if(a3+1 == b3&&a3!='C')
				{
					f4 = 1;
				}
			}
		}
	}
	printf("%d%d%d%d",f1,f2,f3,f4);
	return 0;
}
