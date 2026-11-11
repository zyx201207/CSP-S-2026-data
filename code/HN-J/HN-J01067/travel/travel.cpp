#include<bits/stdc++.h>
using namespace std;
#define sp " "
#define mp make_pair
#define ls p << 1
#define rs p << 1 | 1
typedef long long ll;
string seat1, seat2, ans = "";
int t1, t2;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin>>t1>>seat1>>t2>>seat2;
	bool f = true;
	if(t1 == t2) ans = ans + '1';
	else ans = ans + '0', f = false;
	
	int a = (seat1[0]-'0')*10 + (seat1[1]-'0'), b = (seat2[0]-'0')*10 + (seat2[1]-'0');
	char c = seat1[2], d = seat2[2];
	
	if(f && a == b) ans = ans + '1';
	else ans = ans + '0', f = false;
	
	if(f && (c >= 'A' && c <= 'C' && d >= 'A' && d <= 'C') || (c >= 'D' && c <= 'F' && d >= 'D' && d <= 'F')) ans = ans + '1';
	else ans = ans + '0', f = false;
	
	if(f && abs(c-d) == 1) ans = ans + '1';
	else ans = ans + '0', f = false;
	cout << ans << endl;
	return 0;
}
