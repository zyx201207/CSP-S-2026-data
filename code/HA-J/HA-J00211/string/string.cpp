#include <bits/stdc++.h>
using namespace std;
long long n,sum,j;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		int a;
		string b;
		cin>>a>>b;
		for(int i=1;i<=a;i++) s+=b;
	}
	j=s.size()-1;
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[j]) sum++;
		j--;
	}
	cout<<sum;
	return 0;
}
