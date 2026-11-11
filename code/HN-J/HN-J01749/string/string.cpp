#include<bits/stdc++.h> 
using namespace std;
long long n;
vector<long long> a;
vector<char> c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n; 
	for(long long i = 0;i<n;i++)
	{
		long long tmp1;
		char tmp2;
		cin >> tmp1 >> tmp2;
		a.push_back(tmp1);
		c.push_back(tmp2);
	} 
	for(long long i = 0;i<n;i++)
	{
		for(long long j=0;j<a[i];j++)
		{
			s+=c[i];
		}
	}
	long long ans;
	for(long long i = 0;i<s.size()/2;i++)
	{
		if(s[i]!=s[s.size()-1-i])
		{
			ans++;
		}
	}
	cout << ans-1; 
	return 0;
}
