#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,cnt,c1=1,zong,lenth;
string s;
char chong;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int j;
		cin>>j;
		char c;
		cin>>c;
		zong+=j;
		if(chong==c) c1++;
		chong=c;
		for(int k=0;k<j;k++)
		{
			s+=c;
		 } 
	}
//	cout<<s<<endl;
	lenth=s.size()/2;
	for(int i=0;i<=lenth;i++)
	{
		if(s[i]!=s[s.size()-i-1]) cnt++;
		//cout<<s[i]<<" "<<s[s.size()-i-1]<<endl;
	}	

	cout<<cnt;
	return 0;
 } 
/*
3
2 a
2 b
1 c

2
2 a
3 a

3
2a
4b
3c

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b


*/
