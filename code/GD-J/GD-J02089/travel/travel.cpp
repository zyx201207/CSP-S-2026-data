#include <bits/stdc++.h>
using namespace std;
string a , b , a1 , b1;
int x , y , z , m;
int main(){
	freopen("travel.in" , "r" , stdin);
	freopen("travel.out" , "w" , stdout);
	cin >> a >> b >> a1 >> b1;
	if (a == a1)
	{
		x = 1;
		if (b[0] == b1[0] && b[1] == b1[1])
		{
			y = 1;
			if (b[2] <= 'C' && b1[2] <= 'C' || b[2] >= 'D' && b1[2] >= 'D')
			{
				z = 1;
				if (abs(b[2] - b1[2]) == 1)
					m = 1;
				if (b[2] == 'D' && b1[2] == 'F' || b[2] == 'F' && b1[2] == 'D')
					m = 1;
			}
		}
	}
	cout << x << y << z << m;
	fclose(stdin);
	fclose(stdout);
}
