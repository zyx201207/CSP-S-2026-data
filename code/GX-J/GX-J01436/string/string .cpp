#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main (){
	int n;
	cin>>n;
	 string s;
	 cin>>s;
	for (int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	for (int i=1;i<=n;i++)
	{
		s[i]= s[s.size()+1-i];
	}
	return 0;
}
