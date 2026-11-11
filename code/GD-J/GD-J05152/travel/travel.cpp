#include <bits/stdc++.h>
using namespace std;
string s1,s2;
int c1,c2,a[6],w1,w2,x,y;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	for(int i = 0 ; i<= 4; i++) a[i] = 0;
	if(c1 == c2){
		a[1] = 1;
		w1 = 0; w2 = 0;
		for(int i = 0 ; i<= 1; i++)
		{
			w1 = w1 * 10 + s1[i] - '0';
			w2 = w2 * 10 + s2[i] - '0';
		} 
		x = s1[2] - 'A' + 1; y = s2[2] - 'A' + 1;
		if(w1 == w2){
			a[2] = 1;
			if(x <= 3 and y <= 3) a[3] = 1;
			if( x > 3 and y > 3) a[3] = 1;
			if(x - y == 1 || y - x == 1)
			{
				a[4] = 1;
				a[3] = 1;
				if((x == 3&&y ==4) || (x == 4&&y ==3))
				{
					a[4] = 0;
					a[3] = 0;
				}
			}
		}
	}
	cout << a[1] << a[2] << a[3] << a[4];
	
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
