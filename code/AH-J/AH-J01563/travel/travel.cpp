#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	string p1=s1.substr(0,2);
	char n1=s1[2];
	string p2=s2.substr(0,2);
	char n2=s2[2];
	// cout << c1 << " " << p1 << " " << n1 << "\n";
	// cout << c2 << " " << p2 << " " << n2 << "\n";
	cout << (c1==c2? 1:0);
	cout << (c1==c2 && p1==p2? 1:0);
	cout << (c1==c2 && p1==p2 && (n1-'A')/3==(n2-'A')/3? 1:0);
	cout << (c1==c2 && p1==p2 && (n1-'A')/3==(n2-'A')/3 && ((abs(n2-n1)==1 && (n1-'A')/3==0 && (n2-'A')/3==0) || ((n1-'A')/3==1 && (n2-'A')/3==1))? 1:0);
	return 0;
}
