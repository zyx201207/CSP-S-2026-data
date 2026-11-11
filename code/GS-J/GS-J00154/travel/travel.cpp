#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string C1,S1,C2,S2;
	int cnt = 0,ans = 0,num = 0,lst = 0;
	cin >> C1 >> S1 >> C2 >> S2;
	if(C1 == C2)
	{
		cnt = 1;
	}
	if(S1[0] == S2[0] && S1[1] == S2[1])
	{
		ans = 1;
	}
	cout << cnt << ans << num << lst;
	return 0;
}
