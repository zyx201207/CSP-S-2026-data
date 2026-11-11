#include <bits/stdc++.h>
using namespace std;
int n,m;
string a,b;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> n >> a >> m >> b;
	if(n == m)
		cout << 1;
	else{
		cout << "0000";
		return 0;
    }
	if(a[1] == b[1])
		cout << 1;
	else {
		cout << "000";
		return 0;
	}
	if(a[2] <= 67 && b[2] <= 67 || a[2] > 67 && b[2] > 67)
		cout << 1;
	else {
		cout << "00";
		return 0;
	}
	if(a[2] +1 ==b[2] || a[2] -1 == b[2])
		cout << 1;
	else {
		cout << "0";
	}
	return 0;
}
