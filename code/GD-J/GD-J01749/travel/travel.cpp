#include<iostream>
#include<vector>
#define int unsigned long long
using namespace std;
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;

	string line1 = "";
	char seat1;
	string line2 = "";
	char seat2;

	line1.push_back(s1[0]);
	line1.push_back(s1[1]);
	seat1 = s1[2];

	line2.push_back(s2[0]);
	line2.push_back(s2[1]);
	seat2 = s2[2];

	bool ok1 = (c1==c2);
	cout<<ok1;

	bool ok2 = (line1==line2);
	cout<<(ok1&&ok2);

	bool ok3 = (('A'<=seat1&&seat1<='C')&&('A'<=seat2&&seat2<='C'))
	           ||
	           (('D'<=seat1&&seat1<='F')&&('D'<=seat2&&seat2<='F'));
	cout<<(ok1&&ok2&&ok3);

	bool ok4 = (abs(seat1-seat2)==1)
	           ||
	           (seat1=='D'&&seat2=='F')
	           ||
	           (seat1=='F'&&seat2=='D');
	cout<<(ok1&&ok2&&ok3&&ok4);

	return 0;
}

