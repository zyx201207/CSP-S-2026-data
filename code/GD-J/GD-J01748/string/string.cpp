#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s="";
	while (n--){
		int m;
		char a;
		cin>>m>>a;
		for (int i=1 ; i<=m ; i++) s+=a;
	}
	long long ans=0;
	string s1=s;
	reverse(s.begin(),s.end());
	for (long long i=0 ; i<s.size() ; i++) if (s[i]!=s1[i]) ans++;
	cout << ans/2;
	return 0;
}
