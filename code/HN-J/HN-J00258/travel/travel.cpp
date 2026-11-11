#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string p,q,s1,s2,ans;
	int n,m,flag = 0;
	cin >> n >> p >> m >> q;
	s1 += p[0],s1 += p[1]; 
	s2 += q[0],s2 += q[1];
	if (n == m) ans += '1',flag = 1;
	else ans += '0';
	
	if (s1 == s2 && flag == 1) ans += '1',flag = 2;
	else ans += '0';
	
	if (p[2] == 'F' && flag == 2){
		if (q[2] == 'D') ans+='1',flag = 3;
		else ans+='0';
	}
	else if (p[2] == 'D' && flag == 2){
		if (q[2] == 'F') ans+='1',flag = 3;
		else ans+='0'; 
	}
	else if (flag == 2)
	{
		if (q[2] == 'F' || q[2] == 'D') ans += '0';
		else ans+='1',flag = 3;
	}
	else
	{
		ans+='0';
	}
	if ((int)(p[2] - q[2]) == 1 || (int)(q[2] - p[2] == 1))
	{
		if (flag == 3)
		{
			if ((p[2] == 'C' && q[2] == 'D') || (p[2] == 'D' && q[2] == 'C')) ans+='0';
			else ans+='1';
		}
		else
		{
			ans += '0';
		}
	}
	else ans += '0';
	cout << ans << endl;
	return 0;
}
//ÃÜÂë:Trick||Treat! 
