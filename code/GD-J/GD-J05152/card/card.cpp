#include <bits/stdc++.h>
using namespace std;
int a[500001],c[300001], b[300001],i,n,m,f=0;
void found(int s)
{
	bool d = false;
	for(int i = 1 ; i<=  m ; i++)
	{
	if(d&&c[i]!=0) {c[i]=0;
	f--;
	}
	if(c[i] == s)d = true;
	}
	if(!d) {
		c[f+1] = s;
		f++;
	}
}
 
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1 ; i<= n ; i++)
	{
		cin >>a[i];
	} 
	for(int i = 1 ; i <= n ; i++)
	{
		for(int j= i; j<= n; j++)
		{
			found(a[j]);
		}
		for(int i = 1; i <= m ; i++)
		{
			b[c[i]] += 1;
			//cout << c[i] <<" ";
			c[i]=0;
		}
		f = 0;
		//cout << endl;
	}
	for(int i = 1; i <= m ; i++)
	{
		cout << b[i] <<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
