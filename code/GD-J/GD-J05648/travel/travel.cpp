#include <bits/stdc++.h>
using namespace
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c_yi; 
	int s_yi;
	int c_er;
	int s_er;
	std::cin >> c_yi >> s_yi >> c_er >> s_er;
	a[100] = s_yi;
	b[100] = s_er;
	if (c_yi == c_er)
	{
		cout << '1';
	}
	else{
		cout << '0';
	}
	for(i = 0;i <= 2;i++){
		if (1 <= 1 && a[i] = b[i] && a[i+1] == b[i+1]){
			cout << '1';
		}
		else{
			cout << '0';
		}
		if (i == 2 && ((a[i] != 'C' || a[i] != 'D' )&& (b[i] != 'C' || b[i] != 'D' ))){
			cout << '1';
		}
		else{
			cout << '0';
		}
		if (i == 2 && (a[i] - 1 == b[i] || a[i] == b[i] - 1)){
			cout << '1';
		}
		else{
			cout << '0';
		}
	}
	return 0;
}
