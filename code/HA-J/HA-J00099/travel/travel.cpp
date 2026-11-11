#include <bits/stdc++.h>
using namespace std;
int main()
{
	//ios::sync_with_stdio(false);cin.tie(nullptr);
	freopen("travel.in","r",stdin);freopen("travel.out","w",stdout);
	string c1,c2,c3,c4,a1,a2,a3,a4;
	cin >> c1 >> c2 >> c3 >> c4;
	a1 = "1";a2="0";a3 = "0";a4 = "0";
	if(c1[1] != c3[1])a1 = "0";
	if(c2[1] == c4[1]&&a1[0]=='1')a2 = "1";
	if((c2[2]<='C')&&(c4[2]<='C')&&(a2[0]=='1'))a3="1";
	else if((c2[2]>='E')&&(c4[2])>='E')a3="1";
	if(a3[0] == '1'&&c4[2] - c2[2] == 1)a4="1";
	else if(a3[0] == '1'&&c2[2] - c4[2] == 1)a4="1";
	cout << a1 << a2 << a3 << a4;
	return 0;
}
