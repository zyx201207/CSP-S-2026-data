#include<bits/stdc++.h>
using namespace std;
string a ,b ,c ,d ,sum ,ans;
int wz1 ,wz2;
int main() {
	freopen("travel.in" ,"r" ,stdin);
	freopen("travel.out" ,"w" ,stdout);
	cin >> a >> b >> c >> d;
	if  (a == c)
	cout << "1";
	else{
		cout << "0000";
		return 0;
	}
	for (int i = 0; i < b.size() - 1; i++)
	{
		sum += b[i];
	}
	for (int i = 0; i < d.size() - 1; i++)
	{
		ans += d[i];
	}
	if (sum == ans)
	{
		cout << "1";
	}
	else 
	{
		cout << "000";
		return 0;
	}
	wz1 = b[2];
	wz2 = d[2];
	if ((wz1 >= 'A' && wz1 <= 'C' && wz2 >= 'A' && wz2 <= 'C') || (wz1 >= 'D' && wz1 <= 'F' && wz2 >= 'D' && wz2 <= 'F'))
	cout << "1";
	else
	{
		cout << "00";
		return 0;
	}
	if (wz1 > wz2)
	{
		if (wz1 - wz2 == 1 && wz1 != 'D'){
			cout << "1";
			return 0;
		}
	}
	else {
		if (wz2 - wz1 == 1 && wz2 != 'D'){
			cout << "1";
			return 0;
		}
		
	}
	cout << "0";
}

