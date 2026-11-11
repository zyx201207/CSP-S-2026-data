#include<bits/stdc++.h>
using namespace std;
int huiwen(string s)
{
	int l,r,cnt=0;
	l=0;
	r=s.size();
	while(r-l>=1)
	{
		if(l!=r)
			cnt++;
		r--;
		l++;
	}
	return cnt;
}
struct strings{
	int m;
	char c;
}str[200002];
int main()
{
	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	int n;
	cin >>n;
	for(int i=0;i<n;i++)
	{
		cin >> str[i].m >> str[i].c ;
	}
	string s;
	for(int i=0;i<n;i++)
	{
		s+=str[i].m*str[i].c;
	}
	cout << huiwen(s);
	return 0;
}
