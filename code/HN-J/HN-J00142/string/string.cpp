#include<bits/stdc++.h>
using namespace std;
long long n;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		int a;
		char c;
		cin>>a>>c;
		for(int j=0;j<a;j++)
		s=s+c;
	}
	string ss=s;
	reverse(s.begin(),s.end());
	if(ss==s){
		cout<<0;
	}
	else{
		long long cnt=0;
		for(int i=s.size()/2;i<s.size();i++){
			if(ss[i]!=s[i])
			cnt++;
		}
		cout<<cnt;
	}
	return 0;
}
