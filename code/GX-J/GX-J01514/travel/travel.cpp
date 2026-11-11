#include<bits/stdc++.h>
using namespace std;
int main()
{
	fropen("string.in", "r", stdin);
	fropen("string.out", "w", stdout);
	int n;
	cin >> n;
	
	for(int i=1;i<=n;i++)
	{
		if(n>=4)
			cout << "A" << "B" << "C";
		else if(5<=n||n<=10)
			cout << "A" << "B";
		else if(11<=n||n<=14)
			cout << "A";
		else if(15<=n||n<=17)
			cout << "D";
		else
			cout << " ";
	}
	
	rutern 0;
}
