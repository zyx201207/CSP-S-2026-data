#include<bits/stdc++.h>
using namespace std;
int n[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    int tn,m;
    scanf("%d %d",&tn,&m);
    for(int i = 1;i <= tn;i++)
    {
    	int a;
    	scanf("%d",&a);
    	int ttn[1000000005];
    	int j = 1;
    	while(a != 0)
    	{
    		int b = a % 2;
    		ttn[i] = b;
    		a = (a - b) / 2;
    		i++;
		}
		for(int k = 1; k <= j;k++)
		{
			n[i] = n[i] * 10 + ttn[j - k + 1];
		}
	}
	for(int i = 1;i <= tn;i++)
		{
			for(int j = 1; j <= tn;j++)
			{
				cout<<(n[i] & n[j]);
			}
		}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
