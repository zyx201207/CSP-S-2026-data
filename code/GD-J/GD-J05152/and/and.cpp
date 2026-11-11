#include <bits/stdc++.h>
using namespace std;
int a[20000001], sum = 0,sun = 0,m,n;
/*int check(int ligh,int high,int h)
{
	if(h = m) return 0;
	for(int i = ligh ; i <= n; i++)
	{
		sun = 0;
		for(int j = high ; j <= n ; j++)
		{
			check(i,j,h + 1);
			if(a[i] & a[j] > sun) sun = a[i] & a[j];
			
		}
		if(sun > sum) sum = sun;
	}
	return 0;
}
*/
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1 ; i<= n ; i++) cin >> a[i];
	//sort(a + 1, a+ n + 1);
	for(int i = 1 ; i <= n; i++)
	{
		sun = 0;
		for(int j = i ; j <= n ; j++)
		{
			if(a[i] & a[j] > sun) sun = a[i] & a[j];
			
		}
		if(sun > sum) sum = sun;
	}
	
	//check(1,1,m);
	cout <<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
