#include<bits/stdc++.h>
using namespace std;

long long n,m,ans;
char c;
string s,s1;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> m >> c;
		for(int j=0;j<m;j++)
			s+=c;
	}
	for(int i=s.size()-1;i>-1;i--)
		s1 += s[i];
	for(int i=0;i<s.size();i++){
		if(s[i] != s1[i]){
			ans++;
		}
	}
	 
	
	cout << ans/2;
	return 0;
}
