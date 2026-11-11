#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 0x3f3f3f3f
string a,b,c,d;
int p1,p2;
int to_int(string &a,int ending)
{
	int p = 0;
	while(a[p] == 0) p++;
	int return_val = 0;
	for(;p < ending;p++)
	{
		return_val *= 10;
		return_val += a[p] - '0';
	 } 
	return return_val;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> b >> c>> d;
	p1 = to_int(a,(int)a.size()),p2 = to_int(c,(int)c.size());
	if(p1 != p2) {cout << "0000";return 0;}
	cout << '1';
	p1 = to_int(b,(int)b.size() - 1),p2 = to_int(d,(int)d.size() - 1);
	if(p1 != p2) {cout << "000";return 0;}
	cout << '1';
	char cnt1 = b.back(),cnt2 = d.back();
	if(cnt1 < cnt2) swap(cnt1,cnt2);
	if(cnt1 == 'D')
	{
		if(cnt2 == 'F') cout << "11";
		else cout << "00";
		return 0;
	}
	if(cnt1 == 'F')
	{
		if(cnt2 == 'D') cout << "11";
		else cout << "00";
		return 0;
	}
	cout << 1;
	if(cnt1 > cnt2) swap(cnt1,cnt2);
	if(cnt1 == 'A' && cnt2 == 'C') cout <<"0";
	else cout << 1;
	return 0;
} 
