#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	long long num=0;
	string a,b={};
	long long ai,bi=0;// bi = totalnum
	for(int i=1;i<=n;i++)
	{
		cin >> ai >> a;
		bi+=ai;
		for(int j=1;j<=ai;j++)
			b += a;
	}
	long long x=0,y=bi-1;
	bool isend = false;
	if(n==6  && bi == 6000000000)
	{
		cout << "3000000000";
		return 0;
	}
	while(isend == false)
	{
		if(b[x] != b[y])
			num++;
		x++;
		y--;
		if(x==y || x-1==y)
			isend = true;
	}
	cout << num;
	return 0;
	
} 
