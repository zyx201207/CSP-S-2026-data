#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,m;
	long long cnt=0; 
	cin>>n;
	char x;
	string s;
	for(int i=1;i<=n;i++){
		cin>>m;
		cin>>x;
		for(int j=1;j<=m;j++)
			s+=x;
	}
	for(int i=0, j=s.length()-1;i<s.length()/2;i++,j--){
		if(s[i]!=s[j]) cnt++;
	}
	cout<<cnt; 
	return 0;
}
