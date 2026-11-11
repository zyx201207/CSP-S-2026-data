#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	long long count = 0, n;
	cin >> n;
	string str = "";
	
	for(int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		count += num;
		
		string temp1;
		cin >> temp1;
		
		for(int j = 0; j < num; j++)
			str += temp1;
	}
	
	int l = 0, r = count, ans = 0;;
	
	while(r >= l)
	{
		string tempA = str.substr(l, 1);
		string tempB = str.substr(r, 1);
		
		if(tempA != tempB)
			ans ++;
			
		l ++;
		r --;
	}
		
	cout << ans;
	
	return 0;
}
