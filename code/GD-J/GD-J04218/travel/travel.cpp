#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 1e5+5;

struct Person{
	int id; // 车厢号 
	int seat; // 排号 
	char sid; // 座位号 
	int side; // 哪一侧 
	int de0(string s)
	{
		if(s[0] == '0') return (s[1] - '0');
		else return ((s[0] - '0')*10 + s[1] - '0');
	}
	void input()
	{
		string s;
		cin>>s;
		// s: 01~17
		id = de0(s);
		cin>>s;
		sid = s[2];
		s.pop_back();
		seat = de0(s); 
		if(sid == 'D' || sid == 'F') side = 0;
		else side = 1;
	}
	bool near(Person &o)
	{
		if(side == 0)
		{
			if(sid == 'D' && o.sid == 'F') return 1;
			if(sid == 'F' && o.sid == 'D') return 1;
		}
		else
		{
			if(sid == 'A' && o.sid == 'B') return 1;
			if(sid == 'B' && o.sid == 'A') return 1;
			if(sid == 'B' && o.sid == 'C') return 1;
			if(sid == 'C' && o.sid == 'B') return 1;
		}
		return 0;
	}
};

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	Person a,b;
	a.input(), b.input();
	
	// 是否在同一节车厢
	if(a.id != b.id) 
	{
		cout<<"0000";
		return 0;
	}
	cout<<1; 
	
	// 否在同一节车厢的同一排 
	if(a.seat != b.seat)
	{
		cout<<"000"; // 前面已经输出过 1 个 1 了 
		return 0;
	}
	cout<<1;
	
	// 是否在同一节车厢的同一排，且位于过道的同一侧
	if(a.side != b.side)
	{
		cout<<"00"; // 前面已经输出过 2 个 1 了 
		return 0;
	}
	cout<<1;
	
	// 是否相邻
	bool f = (a.near(b));
	cout<<f;
	
	return 0;
} 
