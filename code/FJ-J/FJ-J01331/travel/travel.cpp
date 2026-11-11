#include<bits/stdc++.h>
using namespace std;
//½âÑ¹ÃÜÂë Trick||Treat! ¼À 

const int N = 100005;

string s1, s2, s3, s4;
int a[10], b[10];

int rn(string s)
{
	int res = 0;
	for(int i = s.size(); i >= 1; i--)
	{
		if(s[i - 1] < '0' || s[i - 1] > '9')continue;
		int nw = s[i - 1] - '0';
		res = res * 10 + nw;
	}
	return res;
}

bool ch1()
{
	if(a[1] != b[1])return 0;
	return 1;
}

bool ch2()
{
	if(a[1] != b[1])return 0;
	if(a[2] != b[2])return 0;
	return 1;
}

bool ch3()
{
	if(a[1] != b[1])return 0;
	if(a[2] != b[2])return 0;
	if(a[4] != b[4])return 0;
	return 1;
}

bool ch4()
{
	if(a[1] != b[1])return 0;
	if(a[2] != b[2])return 0;
	if(a[4] != b[4])return 0;
	if(a[4] == 2 && b[4] == 2)return 1;
	if(abs(a[3] - b[3]) == 1)return 1;
	return 0;
}

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout); 
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> s1 >> s2 >> s3 >> s4;
	a[1] = rn(s1);
	a[2] = rn(s2);
	b[1] = rn(s3);
	b[2] = rn(s4);
	a[3] = s2[s2.size() - 1] - 'A' + 1;
	b[3] = s4[s4.size() - 1] - 'A' + 1;
	if(a[3] <= 3)a[4] = 1;
	else a[4] = 2;
	if(b[3] <= 3)b[4] = 1;
	else b[4] = 2;
	
	cout << ch1() << ch2() << ch3() << ch4();
	
	return 0;
}  
