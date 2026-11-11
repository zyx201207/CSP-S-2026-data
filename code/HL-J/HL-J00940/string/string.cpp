#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,sum;
string s;
int x;
char y;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y;
		for(int j=1;j<=x;j++)
			s+=y;
	}
	string s1=s;
	reverse(s1.begin(),s1.begin()+s1.size());
	if(s1==s)
	{
		cout<<"0";
		return 0;
	}
	int len=s.size();
	for(int i=0;i<=len/2-1;i++)
	{
		if(s[i]!=s[len-1-i])
			sum++;
	}
	cout<<sum;
	return 0;
}
/*
3
2 a
2 b
1 c
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

*/